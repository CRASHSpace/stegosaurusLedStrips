stegosaurusLedStrips
====================

Arduino code for controlling strips and sequences of address LEDs for wearing down the back

Aere is the data from the supplier:
 - https://www.sparkfun.com/products/11020

All this code depends on an Arduino library for communication with the LED strip. It was referenced from the sparkfun site:
 - http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Components/LED/WS2801-Library.zip

Here are the pin outs and colors for this particular strip and our code: 
 - Red – VCC (VIN 5vdc)
 - Yellow – GND 
 - Green – Data (pin 2) 
 - Blue – Clock (pin 3)