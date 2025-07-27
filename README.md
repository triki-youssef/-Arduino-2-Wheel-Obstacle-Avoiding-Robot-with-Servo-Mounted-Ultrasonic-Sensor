# -

 
<h1> 🚗 🤖 Arduino 2-Wheel Obstacle Avoiding Robot with Servo-Mounted Ultrasonic Sensor</h1>

<h2> ✅ Description</h2>
A smart Arduino-powered 2-wheel robot that autonomously avoids obstacles using an ultrasonic sensor mounted on a servo motor. The robot makes real-time decisions based on environmental scanning. When an obstacle is detected in front, the servo turns left and right to check for alternate paths. It selects the optimal direction and avoids obstacles by:

Moving forward when the front is clear

Turning right if both sides are free

Turning to the only available side if one side is blocked

Performing a 180-degree U-turn (demi-tour) if all directions are blocked

<h2> 🧠 Key Features:</h2>

🚗 Autonomous Navigation: Moves without human control and continuously monitors surroundings.

📏 Real-Time Obstacle Detection: Uses HC-SR04 ultrasonic sensor to measure front distance.

🔁 Smart Scanning with Servo: Rotates sensor left and right to scan alternative paths.

🤖 Dynamic Path Decision Logic:

Goes forward if clear

Turns right if both sides are clear

Chooses available side when one is blocked

Makes a U-turn (demi-tour) if all directions are blocked

🔌 Efficient Motor Control: Drives two DC motors using the L298N motor driver.

🔋 Battery Powered: Runs on a portable power supply for full mobility.

🧠 Beginner-Friendly Code: Clean, modular Arduino code suitable for learning robotics logic.
<br />


<h2> ⚙️ Components and Tools Used</h2>


<h3>Hardware Components:</h3>

<h4> - Microcontroller:</h4> Arduino Uno



<h4> - Motors:</h4> DC motors with motor driver module , L298N for robot movement





<h4>🔊 HC-SR04 Ultrasonic Sensor: </h4> Distance sensor for obstacle detection

<h4> - Power Supply:</h4> 7.4V, 3000mAh 

<h4> - ⚙️ Servo Motor (SG90) </h4> Rotates ultrasonic sensor to scan left and right

<h4> - Chassis:</h4> Robot base frame with wheels





<h4> - Software and Utilities:</h4>

<h5> - Arduino IDE:</h5> For programming the microcontroller firmware


<h2> - 📁 Files Included : </h2>
In this repository, you will find:

💻 Arduino_Code.ino – The complete Arduino code for obstacle avoidance behavior.

🔌 Wiring_Diagram.png – Circuit diagram showing how all components are connected.

📸 Media/ – Images or videos of the prototype in action.

✅ You will find the code, wiring diagram, and prototype media in the project files.

<h2> - 📸 Demo : </h2>





