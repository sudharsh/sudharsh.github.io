# Copyright 2013 Sudharshan S
# This work is free. You can redistribute it and/or modify it under the
# terms of the Do What The Fuck You Want To Public License, Version 2,
# as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
import sys
import time
import glob
import os

import serial

from jenkinsapi.jenkins import Jenkins

led_states = {
    "BLINKING": 2,
    "ALWAYS": 3,
    "OFF": 4
}

led_pins = {
    "RED": 6,
    "YELLOW": 7,
    "GREEN": 8
}

# LED behaviour for each Jenkins State
jenkins_states = {
    "SUCCESS": {"GREEN": "ALWAYS"},
    "FAILURE": {"RED": "ALWAYS"},
    "UNSTABLE": {"YELLOW": "ALWAYS"},
    "RUNNING": {
        "GREEN" : "BLINKING",
        "RED"   : "BLINKING",
        "YELLOW": "BLINKING"
    },
    "NOT_BUILT": {
        "YELLOW": "BLINKING"
    }
}
  

def ttymodem(baudrate=9600):
    # Change this Glob if you are using Linux
    devices = glob.glob("/dev/tty.usbmodem*")
    if not devices:
        raise Exception("Probably modem not connected")
    board = devices[0]
    return serial.Serial(board, baudrate=baudrate)

def connect(url, job):
    print "Connecting to the jenkins url: {0}".format(url)
    j = Jenkins(url)
    return j[job]
    
def write(board, command, msg, padding=16):
    padded = msg.ljust(padding)
    # The first character of every line that is sent to the board
    # is a 'command' that will be read by the Arduino Sketch to do
    # something
    message = "{0}{1}\n".format(command, padded)
    print "Writing message --{0}--".format(message.strip())
    board.write(message)

def get_leds(build_state):
    """Given a build state, get the line messages to be sent to the board
    For now, just handle RUNNING, FAILURE and SUCCESS builds"""
    commands = []
    if build_state not in jenkins_states:
        return commands
    led_behaviour = jenkins_states[build_state]
    for led_color, led_state in led_behaviour.items():
        pin = led_pins[led_color]
        state = led_states[led_state]
        commands.append(pin)
        commands.append(state)
    return commands
    
def loop(board, job, poll_interval=15):
    print "Sleeping for a bit"
    time.sleep(1)
    print "Poll interval set to {0}".format(poll_interval)
    while True:
        build = job.get_last_build_or_none()
        if not build:
            print "No build found"
            continue
        build_status = build.get_status()
        if not build_status:
            build_status = "RUNNING" if build.is_running else "QUEUED"
        status = "{0} - {1}".format(build_status, build.get_number())
        print "Writing build status {0} to the board".format(status)
        write(board, 1, status)
        led_commands = get_leds(build_status)
        for c in led_commands:
            write(board, c, "", padding=0);
        if build_status in ["RUNNING", "NOT_BUILT"]:
            # Continuosly bombard the board with the
            # blink commands. Looks Knight Riderish
            pass
        else:
            time.sleep(poll_interval)

if __name__ == '__main__':
    # Run this like so
    # python jenkins_status.py <jenkins_url> <job_name>
    # eg: $ python jenkins_status.py https://builds.apache.org Kafra
    url = sys.argv[1]
    job_name = sys.argv[2]
    board = ttymodem()
    job = connect(url, job_name)
    write(board, 0, job_name)
    write(board, 1, "Connecting...")
    loop(board, job)
