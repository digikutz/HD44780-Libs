#!/bin/bash

$NAME= "$1"
#$HEXNAME = NAME
echo "**********************************************"
echo "*Outlaw Programer v 0.01a By: Mebane 12.25.10*"
echo "**********************************************" 

avr-gcc -g -Os -mmcu=atmega168 -c $1.c # makes .o

avr-gcc -g -mmcu=atmega168 -o $1.elf $1.o # makes .elf

avr-objcopy -j .text -j .data -O ihex $1.elf $1.hex #makes .hex

avrdude -p m328p -c usbtiny -U flash:w:$1.hex  # programs chip (atmega168)



