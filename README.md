Flathead Autonomous Quadruped

3D printed Autonomous Quadruped robot using camera vision, all inspired by the Cyberpunk 2077 flathead robot.


<img width="762" height="527" alt="image" src="https://github.com/user-attachments/assets/cbe4c10c-e4d5-4e79-80c2-4a57103146f8" />





Demo Link:

https://drive.google.com/file/d/12_6V4TeB604TGq49_DJ_Ktc-aOF2DAQ_/view?usp=drive_link


Features:

(Work in progress)

-Quadruped robot with 3DOF per leg

-Robot uses AI vision through the Pi camera to navigate its envrionment

-Robot uses AI and Elevenlabs to simulate a rogue AI from Cyberpunk 2077 and can be spoken to

-LEDs light up the front of the robot

-Robotic arms with 3DOF per arm to pick up items


How to run it locally:

Available now — leg inverse kinematics (no hardware required):

Requires g++ (C++11 or later).

    git clone https://github.com/michaelsumin78-hue/flathead_robot.git
    cd flathead_robot/flathead-quadruped_code
    g++ -O2 -o test_ik test_ik.cpp
    ./test_ik

Expected output: round-trip error of 0.0000mm on every test case, plus
standing pose a swing phase sweep


Coming once the hardware is built:

[ ] ESP32-S3 firmware flash (PlatformIO project, board config TBD)

[ ] Gait engine running on hardware

[ ] Pi-side vision and voice pipeline setup

[ ] Full bring-up sequence: power-on order, safety checks, first servo test


How I made this:
The leg geomoetry went through several revisions driven primarily by torque calculation. To add on, the project was initially intended to use dog-like leg structure but I decided to scrap that and redo the legs after looking at in game footage of the robot in Cyberpunk and seeing videos of people developing spider robots that use a different degree of rotation. When I redid, I changed the leg design visually in many ways, but I also added a slot to have a TPU printed part at the soles of the feet to allow more friction and therefore allow the robot to walk easier.

The overall body was developed by using a 3D model to look around the entire body and see how I should model the robot to remain faithful to the game. I did however have to take some creative liberties of my own as I realized that certain parts of the in game robot were not desirable in my project. I added more interior space to have more room for the electronics, cut out parts of the front to have LEDS visible, adjusted certain parts to be longer or shaped differently to hold motors and what not. I also had to slice the robot in half between the leg and the back torso containing the battery as I realized not only would most commercial printers not be able to print the entire thing in one sitting because of the robot's length, but it would also take far too long as just the front of the bot takes 14 hours optimally to print.

Credits:
https://grabcad.com/library/rack-and-pinion-gear-precision-linear-motion-cad-assembly-mechanical-power-transmission-design-1 

Credit to Muhammad Qasim Sajid for creating the rack and pinion gear which I built part of the arm design off of.


