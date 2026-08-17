Wiring reference

I²C bus
ESP32 GPIO8  → PCA9685 SDA, MPU6050 SDA
ESP32 GPIO9  → PCA9685 SCL, MPU6050 SCL

PCA9685 servo channels
0-2    Front-left   coxa / hip / knee
3-5    Front-right  coxa / hip / knee
6-8    Rear-left    coxa / hip / knee
9-11   Rear-right   coxa / hip / knee
12-15  Arm          yaw / pitch / elbow / gripper
16-19 Arm 2         yaw / pitch / elbow/ gripper

Rails
5.5 V  servo bus (XL4016) to 16 servos, 4700 µF at distribution
5.0 V  logic (UBEC) to ESP32, PCA9685, MPU6050, Pi, mic, amp
GND    all returns to bar at battery negative

