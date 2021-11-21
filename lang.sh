#!/bin/bash

lang=$(setxkbmap -query | grep layout)

if [ "$lang" = "layout:     lt" ]; then
    $(setxkbmap us)
else
    $(setxkbmap lt)
fi
