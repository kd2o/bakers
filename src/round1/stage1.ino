#include <Arduino.h>
#include <Servo.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

#define BUTTON_PIN 4
#define MP1 13
#define MP2 12
#define SCP 11
#define SSP 3 
#define trigforward 5
#define echoforward 6
#define trigright 7
#define echoright 8
#define trigleft 9          
#define echoleft 10
#define ENCODER_PIN 2

Servo steering;
MPU6050 mpu6050(Wire);
volatile long encoderCount = 0;

float kp = 1.0;
float kd = 0.1;
float old_error = 0;
float last_d = 0;
float d_filter_alpha = 0.7;
int target_angle = 0;
int turns = 0;

void encoderISR() {
  encoderCount++;
}

void setupEncoder() {
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), encoderISR, RISING);
}

long getEncoderCount() {
  return encoderCount;
}

void resetEncoder() {
  encoderCount = 0;
}

// -------------------- دوال الحساسات --------------------
float get_dis(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance_cm = duration * 0.034 / 2;
  return distance_cm;
}

int ret_avr(int trigPin, int echoPin) {
  int average_dis = 0;
  int samples = 3;
  for (int i = 0; i < samples; i++) {
    int dis_now = get_dis(trigPin, echoPin);
    delay(10);
    average_dis += dis_now;
    delay(2);
  }
  return average_dis / samples;
}

int get_dir() {
  int forwarddis = ret_avr(trigforward, echoforward);
  int rightdis = ret_avr(trigright, echoright);
  int leftdis = ret_avr(trigleft, echoleft);

  if (forwarddis > 100) return 0;
  if (rightdis > 70) return 1;
  return 2;
}


void turn_right() {
  int desired_angle = mpu6050.getAngleZ() - 90;
  while (mpu6050.getAngleZ() < desired_angle) {
    steering.write(65);
  }
  turns++;
} 

void turn_left() {
  int desired_angle = mpu6050.getAngleZ() + 90;
  while (mpu6050.getAngleZ() > desired_angle) {
    steering.write(-65);
  }
  turns++;
}

void move_forward(int speed) {
  digitalWrite(MP1, HIGH);
  digitalWrite(MP2, LOW);
  analogWrite(SCP, speed);
}

void move_backward(int speed) {
  digitalWrite(MP1, HIGH);
  digitalWrite(MP2, LOW);
  analogWrite(SCP, speed);
}

void Stop() {
  digitalWrite(MP1, LOW);
  digitalWrite(MP2, LOW);
  analogWrite(SCP, 0);
}

float Gyro_Pid(int turns1) {
  mpu6050.update();
  float error = target_angle - (mpu6050.getAngleZ() - turns1*90);
  float p = kp * error;
  float d_raw = kd * (error - old_error);
  float d = d_filter_alpha * last_d + (1 - d_filter_alpha) * d_raw;
  float output = p + d;
  old_error = error;
  last_d = d;
  return output;
}

bool isButtonPressed() {
  return digitalRead(BUTTON_PIN) == LOW;
}

void setup(){
  delay(1000);
  Serial.begin(9600);

  pinMode(ENCODER_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(MP1, OUTPUT);
  pinMode(MP2, OUTPUT);
  pinMode(SCP, OUTPUT);
  pinMode(SSP, OUTPUT);
  steering.attach(SSP);

  pinMode(trigforward, OUTPUT);
  pinMode(echoforward, INPUT);
  pinMode(trigright, OUTPUT);
  pinMode(echoright, INPUT);
  pinMode(trigleft, OUTPUT);
  pinMode(echoleft, INPUT);

  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  setupEncoder();
}
int laps=0;

void loop() {


  // move_forward(255);
  // Serial.println(getEncoderCount());

  // if(get_dis(trigforward, echoforward)<100){
  //   int wanted_angle = mpu6050.getAngleZ() + 90;
  //   int steering_angle=0;
  //   while(mpu6050.getAngleZ()<wanted_angle){
  //     steering_angle+=5;
  //     steering.write(90+steering_angle);
  //     Serial.println(get_dis(trigforward, echoforward));
  //   }
  // }
}




// void loop(){
//   Serial.println(get_dis(trigforward, echoforward));
// }


// void loop(){
//   steering.write();
// }         
