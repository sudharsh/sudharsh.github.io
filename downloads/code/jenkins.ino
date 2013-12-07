/*
  Copyright 2013 Sudharshan S
  This work is free. You can redistribute it and/or modify it under the
  terms of the Do What The Fuck You Want To Public License, Version 2,
  as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
*/
#include <LiquidCrystal.h>
#include <Serial.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

/* The input data to the board */
String d_input;
int print_lcd = 0;

int led_pins[] = { 6, 7, 8 };
int led_state;

#define LCD_BACKLIGHT_PIN 13
#define LED_COUNT 3
#define BAUD_RATE 9600

enum SerialCommands {
    // LCD Cursor control
    LCD_SET_ROW_FIRST = 0x30,
    LCD_SET_ROW_SECOND = 0x31,

    // LED States
    LED_SET_BLINKING = 0x32,
    LED_SET_ALWAYS = 0x33,
    LED_SET_OFF = 0x34,

    // LED PINs
    LED_RED = 0x36,
    LED_YELLOW = 0x37,
    LED_GREEN = 0x38
};

void setup()
{
    // Init Serial
    Serial.begin(BAUD_RATE);

    // LCD Display initialization
    pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
    digitalWrite(LCD_BACKLIGHT_PIN, HIGH);
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Waiting...");
    lcd.setCursor(0, 1);
    lcd.print("for Input");

    // Activate all the LEDs
    for (int i=0; i < LED_COUNT; i++) {
        pinMode(led_pins[i], OUTPUT);
        digitalWrite(led_pins[i], HIGH);
    }
}

int command_mode = 1;
int last_led;
int last_led_state;

// Switch off all LEDs
void clearLEDs() {
    for (int i=0; i < LED_COUNT; i++) {
        digitalWrite(led_pins[i], LOW);
    }
}

void clearLCD() {
    d_input = "";
    print_lcd = 0;
}

/* Every input line to the board starts with a single character
   which acts as the command to be executed.
   In our case, these commands do one of the following
   - Set LCD cursor to corresponding row
   - Set the LED whose state has to be changed
   - Set the state of the LED
   Granted, we can have only 9 commands in this implementation ;)
*/
void execCommand(int command) {
    switch(command) {
    case LCD_SET_ROW_FIRST:
        Serial.print("Setting cursor to Row 0");
        lcd.setCursor(0, 0);
        break;
    case LCD_SET_ROW_SECOND:
        Serial.print("Setting cursor to Row 1");
        lcd.setCursor(0, 1);
        break;
    case LED_SET_BLINKING:
        // Cue the Knight Rider theme music
        digitalWrite(last_led, HIGH);
        delay(200);
        digitalWrite(last_led, LOW);
        delay(100);
        break;
    case LED_SET_ALWAYS:
        clearLEDs();
        digitalWrite(last_led, HIGH);
        break;
    case LED_SET_OFF:
        clearLEDs();
        digitalWrite(last_led, LOW);
        break;
    case LED_RED:
        last_led = 6;
        break;
    case LED_YELLOW:
        last_led = 7;
        break;
    case LED_GREEN:
        last_led = 8;
        break;
    }
}

void readSerial()
{
    if (Serial.available() > 0) {
        char recvd = Serial.read();
        /* The first character of each line to the board
           is the command to be executed
        */
        if (command_mode) {
            execCommand(recvd);
            command_mode = 0;
            return;
        }
        switch(recvd) {
        case '\n':
            Serial.print("Board received: ");
            Serial.print(d_input);
            // Setting this flag flushes the data onto the LCD
            print_lcd = 1;
            command_mode = 1;
            break;
        default:
            d_input += recvd;
        }
    }
}


void loop()
{
    readSerial();
    if (print_lcd > 0) {
        lcd.print(d_input);
        clearLCD();
    }
}
