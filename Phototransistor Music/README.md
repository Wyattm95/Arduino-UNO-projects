## Description

This project uses a phototransistor to control the pitch of a piezo buzzer. 
During the first five seconds after startup, the Arduino calibrates the sensor 
by recording the minimum and maximum light levels while the onboard LED is on. 
Once calibrated, the live light readings are mapped to a frequency range (50–4000 Hz), 
allowing the piezo to generate tones that change in real time based on ambient light.

## Wiring Diagram

![Phototransistor Music](Phototransistor%20Music.png)

## Components 
- Arduino
- Breadboard
- Piezo
- Phototransistor
- 1 x 10k Ω resistor
- 2 x Jumper Cabels
- 4 x Misc Wires
