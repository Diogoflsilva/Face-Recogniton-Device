# Face Recogniton Device
This project consist in the development of a device that can recognise the face of the people and display it on a dashboard in node red and activate devices

# Materials
*	ESP32 
*	Huskylens
*	RGB LED
*	Computer
*	Stable Internet connection
*	Jumpers
*	Breadboard

# Circuit
![Circuit](https://cdn.discordapp.com/attachments/958865240915841024/996774110468247642/unknown.png)

# Setting up the camera
* Settings

Go to face recognition on the camera and long press on the selection wheel, after that Select “Learn multiple” and enable it then “Save & Return”
![image](https://user-images.githubusercontent.com/89361033/178749443-b5ce04eb-93a2-4325-872e-c4eb5e0907b1.png)

* Learning Faces

Point the HuskyLens at any faces. When a face is detected, it will be automatically selected by a white frame with words "Face" on the screen. 
Point the “+” symbol at the face, long press the "learning button" to learn the face of the first person. Then release the "learning button", a blue frame with words "Face: ID1" will be displayed if HuskyLens detects the same face，meanwhile, a message "Click again to continue! Click other button to finish" will be displayed. Please short press the "learning button" before the countdown ends if you want to learn the face of another person. If not, short press the "function button" before the countdown ends, or do not press any button to let the countdown ends.
![image](https://user-images.githubusercontent.com/89361033/178749496-d75c03d8-1a8f-4cf2-bba9-8cc91ce5c60d.png)
