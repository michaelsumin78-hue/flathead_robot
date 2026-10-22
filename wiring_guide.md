# Wiring reference

Full schematic: [wiring/Flathead_Wiring.pdf](wiring/Flathead_Wiring.pdf) (KiCad source in [wiring/](wiring/))

![Flathead wiring diagram](wiring/Flathead_Wiring.png)

## Power

| From | To | Notes |
| --- | --- | --- |
| 2S LiPo V+ | 20A blade fuse | XT60 between battery and harness |
| Fuse | KCD1 rocker switch | |
| Switch | XL4016 VIN+, UBEC VIN+, battery divider | switched battery (VBAT_SW) |
| XL4016 | 5.5 V servo bus | 20 servos, 4700 µF at distribution |
| UBEC | 5.0 V logic | ESP32, Pi, amp, LEDs |
| ESP32 3V3 OUT | 3.3 V | PCA9685 x2 logic, MPU6050 |
| Pi 3V3 | 3.3 V | INMP441 mic |
| GND | all returns to bar at battery negative | |

## ESP32 DevKit pins

| Pin | Function |
| --- | --- |
| GPIO21 | I²C SDA: PCA9685 #1, PCA9685 #2, MPU6050 |
| GPIO22 | I²C SCL: PCA9685 #1, PCA9685 #2, MPU6050 |
| GPIO17 | UART TX2 to Pi RX (pin 10) |
| GPIO16 | UART RX2 from Pi TX (pin 8) |
| GPIO34 | Battery sense, 10k / 4k7 divider (8.4 V full charge reads 2.7 V) |

## PCA9685 #1 (address 0x40)

| Channels | Part | Joints |
| --- | --- | --- |
| 0-2 | Front-left leg | coxa / hip / knee |
| 3-5 | Front-right leg | coxa / hip / knee |
| 6-8 | Rear-left leg | coxa / hip / knee |
| 9-11 | Rear-right leg | coxa / hip / knee |
| 12-15 | Arm 1 | yaw / pitch / elbow / gripper |

## PCA9685 #2 (address 0x41, A0 pad bridged, same I²C bus)

| Channels | Part | Notes |
| --- | --- | --- |
| 0-3 | Arm 2 | yaw / pitch / elbow / gripper |
| 4-6 | Eye LED 1 | red / green / blue cathodes |
| 7-9 | Eye LED 2 | red / green / blue cathodes |
| 10-15 | spare | |

Both boards leave V+ unconnected. The servos take power straight from the 5.5 V bus.

## Eye LEDs

Common anode RGB LEDs. The anode goes to 5.0 V. Each cathode goes through a resistor (220 Ω red, 150 Ω green and blue) to its PCA9685 #2 channel. PCA9685 #2 runs in open-drain mode (MODE2 OUTDRV = 0) so its outputs can sink the 5 V LED current.
