# 0. How it works
- The video content will be played on the laptop/desktop, and the output is connected to TV via HDMI.
- The Prismatik software on the laptop/desktop will capture the screen, averaging the edge's pixels colour, and send the command to LED string via serial port.

# 1. Hardware
## Components:
- 5V 3A power adapter (https://www.robotshop.com/ca/en/power-supply-5v-4a.html).
- Arduino Nano (https://www.banggood.com/ATmega328P-Nano-V3-Module-Improved-Version-No-Cable-Development-Board-p-959231.html?rmmds=myorder&cur_warehouse=CN)
- Resistor 220 Ohm 
- Led string: RGB, link: https://www.banggood.com/1M-5M-WS2812B-5-Pins-RGBW-RGBWW-4-IN-1-LED-Strip-Light-Non-Waterproof-DC5V-p-1211152.html

## Schematic:
- Connect GND of 5V power supply to GND of arduino to keep sync
- Digital output of Arduino -> resistor -> data line of led string

# 2. Arduino Code
- See arduino_led_tring.ino
- Edit the correct number of led
- Edit the output pin (Default is D3).

# 3. Software 
- Prismatik folk, from: https://github.com/psieg/Lightpack/releases
- Add new device and setup the correct led numbers.
