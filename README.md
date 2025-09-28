<h1>Project Documentation | Team bakers | Palestine</h1>

----
<h1>introduction</h1>



We are the Bakers Team, and we would like to introduce you to our autonomous car, Cookie!
Cookie is more than just a project – it’s a combination of innovation, teamwork, and problem-solving. Designed for the WRO Future Engineers category, Cookie is equipped with smart sensors, precise control systems, and advanced programming that allow it to navigate, adapt, and make decisions on its own.

Our goal with Cookie is not only to compete but also to explore real-world applications of autonomous technology. From improving road safety to reducing human error, autonomous cars represent the future of mobility – and Cookie is our step toward that future.

Through this project, we’ve learned to collaborate, test ideas, and overcome challenges together. Every component, from the hardware to the software, was built and fine-tuned by our team to ensure Cookie can handle dynamic environments while staying efficient and reliable.

We’re excited to share our journey with you, and we hope Cookie inspires others to keep building, innovating, and dreaming big.

----
<h1>Electrical circuit</h1>
<img src="schemes/Electrical circuit.png" width="450">
<h3>In this circuit, the motor driver (L298N) is powered directly from the battery, and it also provides a regulated 5V output that powers the Arduino Uno. The three ultrasonic sensors and the servo motor receive their 5V supply from the Arduino’s 5V pin, distributed through the breadboard. The gyroscope (MPU6050) and the motor encoder are powered by the Arduino’s 3.3V pin through the breadboard for signal connections. The motor driver is controlled by the Arduino through pins 13 and 12 for motor direction, and pins 11 and 3 (PWM) for motor speed. The ultrasonic sensors are wired with trig and echo pins: forward on 5 and 6, right on 7 and 8, and left on 9 and 10. Finally, the encoder signal is read on pin 2, enabling the Arduino to measure motor rotation for precise navigation.</h3>


----
<h1>3D design</h1>
<img src="schemes/basee.png" width="450"> 
<h3>This is the newly added layer of the car.  
The 3D model illustrates the updated design.  
It has been integrated with the existing structure.  
All components are aligned for proper assembly.  </h3>


----

<h1> content </h1>

<details>
<summary>1. Team Photos (t-photos)</summary>

- [t-photos README](t-photos/README.md)
- [Team photo file](t-photos/488643484_2903240211307105...)  

</details>

<details>
<summary>2. Vehicle Photos (v-photos)</summary>

- [v-photos README](v-photos/README.md)

</details>

<details>
<summary>3. Video</summary>

- [video README](video/README.md)
- [Video file](video/video.md)

</details>

<details>
<summary>4. Schemes & Diagrams (schemes)</summary>

- [schemes README](schemes/README.md)

</details>

<details>
<summary>5. Source Code (src)</summary>

- [src/round1 README](src/round1/README.md)

</details>

<details>
<summary>6. 3D Models (models)</summary>

- [.gitkeep](models/.gitkeep)

</details>

<details>
<summary>7. Other Files (other)</summary>

- [.gitkeep](other/.gitkeep)

</details>

<h1>Parts List</h1>
<table>
  <tr>
    <th>Component</th>
    <th>Image</th>
  </tr>
  <tr>
    <td>Arduino Uno R3</td>
    <td><img src="components/Arduino Uno R3.jpg" width="150"></td>
  </tr>
  <tr>
    <td>Raspberry Pi 4</td>
    <td><img src="components/Raspberry Pi 4" width="150"></td>
  </tr>
  <tr>
    <td>Motor Driver L298N</td>
    <td><img src="components/L298N.jpg" width="150"></td>
  </tr>
  <tr>
    <td>Picam 3</td>
    <td><img src="components/picam.jpeg" width="150"></td>
  </tr>
  <tr>
    <td>Servo Motor</td>
    <td><img src="components/Servo_MG996R.jpg" width="150"></td>
  </tr>
  <tr>
    <td>UltraSonic HC-SR04</td>
    <td><img src="components/ultrasonic.png" width="150"></td>
  </tr>
  <tr>
    <td>Gyroscope (MPU-6050)</td>
    <td><img src="components/mpu6050.png" width="150"></td>
  </tr>
  <tr>
    <td>Battery (12V)</td>
    <td><img src="components/battery.jpeg" width="150"></td>
  </tr>
  <tr>
    <td>Robot kit</td>
    <td>/<a href="https://technolab.ps/detail/5451"><img src="components/RobotKit.png" width="150"></a></td>
  </tr>
</table>


----

<h2>Team coach</h2>

- <a href="https://www.facebook.com/HamedZaferSwaiseh">Hamed Swaiseh<a/> - Email : <Hamed7710@gmail.com>

  <img src="t-photos/488643484_29032402113071058_8942174443452896184_n.jpg" Width="450">

----
# 👥 Meet Our Team

---

### 🎯 Yazan Hindia
![Yazan](t-photos/)


**Age: 14**


**School: Rasheed Moneeb Almasry puplic school**

**GitHub:** [kd2o](https://github.com/kd2o)  
**Email:** [yazanhendia@gmail.com](mailto:yazanhendia@gmail.com)  

I'm passionate about **programming, cybersecurity, and building things from scratch**.  
I love tackling problems logically, experimenting with new technologies, and giving *Cookie* its brain.  
Outside of code, I enjoy adding humor and creativity to everything I do.
---

### 🎨 Rayan Rino
<img src="t-photos/rayan.png">


**Age: 14**


**School: The British Scientific School**

**Email:** [rinoorayan14@gmail.com](mailto:rinoorayan14@gmail.com)  

I'm the **creative thinker** of the team.  
With a sharp eye for design and a problem-solving mindset, I makes sure *Cookie* doesn’t just run well, but looks amazing too.  
I also the motivator who keeps the team’s energy high!
---

### 🔧 Omar Sharaf


 <img src="t-photos/omar.png" width="150">


**Age**: 16

**School**: Industrial Secondary School

**Email:** [omarsharaf426@gmail.com](mailto:omarsharaf426@gmail.com)  

**Omar is the **hardware wizard**.  
I love working with circuits, sensors, and motors, making sure *Cookie* can move, turn, and sense the world around it.  
My focus and precision keeps the technical side of the project solid and reliable.**


## Gyro PID Control

This function implements a simple **PD controller** for a gyro sensor (MPU6050).  
It adjusts the output based on the difference between the target angle and the current gyro angle.

# Gyro PID Control

This project demonstrates a **PD (Proportional-Derivative) controller** for the MPU6050 gyro sensor, used to control the angle of a robot or vehicle accurately.

## Description

The PD controller calculates the error between the desired angle (`target_angle`) and the current gyro angle. It then applies **proportional** and **derivative** corrections to minimize the error smoothly.

## Code Example

```cpp
// -----------------------------------------
// PD controller for MPU6050 gyro sensor
// -----------------------------------------

float kp = 1.0;        // Proportional gain
float kd = 0.1;        // Derivative gain
float old_error = 0;   // Previous error value
float last_d = 0;      // Previous derivative value
float d_filter_alpha = 0.7;  // Smoothing factor for derivative
int target_angle = 0;  // Desired angle
int turns = 0;         // Number of 90° turns completed

float Gyro_Pid(int turns1) {
  mpu6050.update();  // Update gyro readings

  // Calculate error: target angle - current angle - turns adjustment
  float error = target_angle - (mpu6050.getAngleZ() - turns1 * 90);

  // Proportional term
  float p = kp * error;

  // Raw derivative term
  float d_raw = kd * (error - old_error);

  // Filtered derivative to smooth sudden spikes
  float d = d_filter_alpha * last_d + (1 - d_filter_alpha) * d_raw;

  // PD output
  float output = p + d;

  // Update previous values for next iteration
  old_error = error;
  last_d = d;

  return output;  // Return control value
}
