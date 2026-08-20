

| | |
| :--- | :--- |
| **Title** | Flathead |
| **Author** | Mike |
| **Description** | A 12-DOF quadruped that walks, balances, and looks like it crawled out of Night City |
| **Created At** | 2026-08-16 |

Leg Making

![image](https://cdn.hackclub.com/01a010c0-a160-79ed-93fc-5f1c62bb4d16/image.png)

This is the first part to the start of my leg design is more of a rough draft. You can see that the design is mainly based off of using metal servo horns. In my experience plastic ones do not last very long and I wanted to be more careful considering the motors I will be using are mg996rs. 
![image](https://cdn.hackclub.com/01a010c3-425b-7a0b-bf37-3dd53b1d27e0/image.png)
![image](https://cdn.hackclub.com/01a010c3-ccae-77ba-855c-a39de6cbc843/image.png)

This is where I started mapping out the general shape of the leg. I pulled up a 3d model of the in game version of the robot and tried to model it to get as close as possible while accounting for the lengths of the joints which I tried keeping around 75mm so the math for IK will be easier to do.

![image](https://cdn.hackclub.com/01a010c6-20af-7853-8144-d43114047cd6/image.png)

Body work done before vacation

This iteration shows what is basically the finished leg design but I made a small iteration at least in the model where the joint is bent backwards(this will not stay). I added holders so along the leg the wiring can stay in place and I started adding the connections required  to allow it to be attached to the main body.

Side Note:
I would also like to say that the leg design of the in game robot would be very difficult to make work and for it to be stable so I took some creative liberties.

![image](https://cdn.hackclub.com/01a010cb-8cf5-7f12-9af4-6e60f9d289ee/image.png)

The attached image displays some of the final progress I would make before going on vacation. A lot of this will become subject to change but right now I begin to model the front face of the robot.

![image](https://cdn.hackclub.com/01a010ce-01fc-7796-a631-371d05beb9de/image.png)

A lot of this was purely cosmetic and just so I could feel happy about the state of the project before I leave.

Body and Arm Development

![image](https://cdn.hackclub.com/01a010d3-27b5-78c7-8f8b-a15207825655/image.png)

![image](https://cdn.hackclub.com/01a010d3-d58e-717c-bd3b-0ba45c6cf81f/image.png)

I begin to model the back of the robot to be similar to the in game one. Being about happy with the progress for now, I move on to the arm layout. I am using sg90 servo motors here so I import a model I found online and begin modeling the base of the arm around it. I have one yaw at the base and two pitches as I get closer to the front. The arms take less of the focus here so I wanted to make them simpler but I still want them to be functional. 

![image](https://cdn.hackclub.com/01a010d8-f658-7b81-96bb-57cd5d7651d2/image.png)

I import a model of a matching round and straight gear set to develop a rack and pinion gripper design. I begin to develop a mount to keep the straight gear in place while developing the gripper that should move to close in on a object.

![image](https://cdn.hackclub.com/01a010da-e45e-75cf-b870-36126a86d62e/image.png)![image](https://cdn.hackclub.com/01a010da-62b2-75cb-822f-666f29ff3586/image.png)

This is about the finished version of the model for the arms. I added the static half of the gripper and I spent some time making the arms look better as well as the base for the arms. I also added areas for the wires to go through similar to what I did for the legs.

Side Note:
https://grabcad.com/library/rack-and-pinion-gear-precision-linear-motion-cad-assembly-mechanical-power-transmission-design-1
I have attached the 3d model I used for the rack and pinion gear which I have built upon to be usable in my model. Everything else in the model is either a placeholder asset or made by me.

Side Note: 
I mirrored the leg designs on all sides but it was about one command so I avoided going too in depth on it.

Final Modeling Details

![image](https://cdn.hackclub.com/01a010dd-b2f2-7214-b865-022b51b94544/image.png)

For starters I begin to develop the roof designs for the robot to conceal the electronics that will be placed inside. 

![image](https://cdn.hackclub.com/01a010e0-f63b-7915-b86d-4f28c1be17fa/image.png)

This is where I realized that my original face design for the robot needs to be adjusted, as I needed somewhere to conceal and keep my camera module. I decided to remove the original design I made for the camera and begin making a usable one. I used a raspberry pi camera placeholder and modeled around it while trying to keep the original essence of the design.

![image](https://cdn.hackclub.com/01a010e3-7c53-79ae-a523-a634c582db7f/image.png)

![image](https://cdn.hackclub.com/01a010e3-dd18-7651-bd69-de7ca48ae24b/image.png)

I finish the overall looks of the outside of the camera and decide to move it more inward into the design. You can see the result of this by me carving out a space in the inner space of the front of the robot where you can slot in the camera. 

![image](https://cdn.hackclub.com/01a010e4-a8c2-7c93-8eea-c1805ba525e9/image.png)

![image](https://cdn.hackclub.com/01a010e5-060e-764c-995c-a9944c49a65c/image.png)

Considering the importance of the gyroscope and me wrapping things up, I made a holder for the gyroscope to keep it in place.

![image](https://cdn.hackclub.com/01a010e6-5cf4-7425-8e3e-bca08565ca96/image.png)

This is the compartment the battery will be going and I added small latches to keep the battery in place as considering it is a lipo, more care needs to be put into it. 

![image](https://cdn.hackclub.com/01a010e7-21b2-719d-b47a-3dead8ca21c8/image.png)

For the finishing touches I added somewhere to keep the speaker in place on the outside to project the robot's voice better and I also made a couple more adjustments to the back to make it more visually appealing.

