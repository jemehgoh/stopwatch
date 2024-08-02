## Description

A stopwatch implemented using a STM32F303RE MCU on a Nucleo-64 board. The code for this project was written on the Keil uVision 5 IDE, and with the STM32F303RE startup files and
CMSIS header files (included within the IDE). 

## Functionality

The stopwatch has a 4-digit 7-segment display, and has two buttons. The functionality of these buttons is as follows:
- Button 0: Starts or stops the stopwatch
- Button 1: Takes a split (if the stopwatch is counting up) or resets the stopwatch (if the stopwatch is not counting up)

The 4-digit 7-segment display displays the current time elapsed in minutes (first 2 digits) and seconds (last 2 digits)

## Hardware

The 4-digit 7-segment display used to display the time comprised two 2-digit common-cathode 7-segment displays. These displays were connected to 28 GPIO pins on the Nucleo-64
board, with a 220-ohm current-limiting resistor connected in series for each pin.

The two buttons were wired to provide an active-low output, with 10-kohm resistors used as pull-up resistors.



