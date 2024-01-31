# PropWash Simulation KAP140 LCD
![PWS_AutopilotLCD](https://github.com/PropWSim/PWS_AutopilotLCD/blob/main/images/LCD.jpg)

This 3.3V LCD is 5V tolerant on logic inputs.

## Wiring
Pin|Signal
---|------------
1|Backlight Anode, +3.3V. Use a 140R series resistor for +5V
2|Backlight Cathode, GND
3|Vss, GND
4|SCL
5|SDA
6|Vdd, +3.3V or +5V

## Initialization
The LCD driver IC needs 50ms after Vdd has stabilized to become ready to accept commands.
PWS_AutopilotLCD::begin(uint8_t IVA) will initialize the driver chip, clear the display register and by default set the Internal Voltage Adjust to 0 which translates to 1.0*Vdd. To prevent damage to the LCD, the drive voltage needs to be 3.3V.

IVA|LCD drive voltage
---|-----------------
0x0|1.000 × Vdd  (Default)
0x1|0.957 × Vdd
0x2|0.918 × Vdd
0x3|0.882 × Vdd
0x4|0.849 × Vdd
0x5|0.818 × Vdd
0x6|0.789 × Vdd
0x7|0.763 × Vdd
0x8|0.738 × Vdd
0x9|0.714 × Vdd
0xA|0.692 × Vdd
0xB|0.672 × Vdd
0xC|0.652 × Vdd
0xD|0.634 × Vdd
0xE|0.616 × Vdd
0xF|0.600 × Vdd

### Example
Vdd = 5V. IVA needs to be set to scale the drive voltage to 3.3V; 3.3/5 = 0.66. Choosing 0xB or 0xC for IVA will correctly drive the LCD.

    /* Remember to wait at least 50ms from power on */
    PWS_AutopilotLCD	APlcd;
    APlcd.begin(0x0B); //IVA chosen for 5V logic.
