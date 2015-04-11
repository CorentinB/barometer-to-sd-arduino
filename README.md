# Barometer to SD - Arduino
Small code to use a barometer (to get pressure and temp) on an Arduino Mega/Uno and send it to an SD card.

If you are using an Arduino UNO, the pin 53 used at the line 21 and 23 is not the same, it's 4 or 10 or 11.

Pressure and Temp (in °C) are saved in a .csv file (to make a graph easily) but you can change it into .txt or something else.

The barometer used here is te BMP085, you can use an other but you have to precise an other library, here I use the Adafruit_BMP085.h (wich you have to download if you are using the BMP085).

At the end of the file, there is a line of code who can set a delay between two measure.
