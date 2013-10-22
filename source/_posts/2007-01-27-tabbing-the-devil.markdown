---
author: sudharsh
comments: true
date: 2007-01-27 15:54
layout: post
slug: tabbing-the-devil
title: Tabbing the DEviL
wordpress_id: 45
categories:
- FOSS and Linux
- Tips
---

Forget the emacs vs vi (or vim) battles.

Vim has tabs in its latest 7.0 release. Quite simple actually. A new tab is as easy as doing a

`:tabnew "filename"`

Moving between tabs is easy too..

`:tabp `
`:tabn`

for moving to the previous and the next tab respectively

For closing the tab

`:tabclose "wahtever"`

Heres a neat thing I learnt from the Inter-Web. You can map the "tabn" and "tabp" to keyboard shortcuts. For this open you .vimrc (..or create one if it doesnt exist), and add this,

`nnoremap <silent> <C-n> :tabnext<CR>`
`noremap <silent> <C-p> :tabprevious<CR>`

Long live, the cult of vi...
