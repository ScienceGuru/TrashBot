#include <Servo.h> 


/*
 * Sarah Wood 
 * OWATC
 * Embedded Programming 
 * Summer 2016
 * 
 * Trash-Bot Arm
 * 
 * 
 * I tried to see how cheaply I could do this. So far, I'm at $29.00 
 * The 9g servos were super-cheap. 10 for $20.00
 * The structural/mechanical parts were mostly found around the house. 
 * I did purchase an acrylic ruler, and an acrylic folding stand a thrift shop. $1.00
 * 
 * I prototyped with wooden sticks -- like Popsicle sticks, but wider for spreading wax.
 * The "wrist", "hand", and gripper parts are scavenged from a broken RC helicopter.
 * 
 * 
 * I used a breadboard and other components that I already had. 
 * I did end up needing to buy potentiometers for control.
 * 
 * I powered the servos separately from the Arduino. I used an old desktop computer power supply to give a full 5v at decent amperage for max torque on the servos.
 * 
 * 
 * 
 * 
 */

int ShoulderReading;
int ShoulderPotPin = A0;  
int ShoulderServoPin1 = 8;
Servo ShoulderServo1; 
int ShoulderServoPin2 = 9;
Servo ShoulderServo2;

int ElbowReading;
int ElbowPotPin = A1;
int ElbowServoPin1 = 10;
Servo ElbowServo1;
int ElbowServoPin2 = 11;
Servo ElbowServo2;

int WristPotPin = 3; //not used yet
int WristServoPinTilt; //give this a value if/when we use it
Servo WristServoTilt; // Tilt is probably more applicable than axial rotation

int GripperReading;
int GripperPotPin = A2;
int GripperServoPin1 = 12;
Servo GripperServo1;
int GripperServoPin2 = 13;
Servo GripperServo2;

 
void setup() 
{ 
  ShoulderServo1.attach(ShoulderServoPin1);  
  ShoulderServo2.attach(ShoulderServoPin2); 
  ElbowServo1.attach(ElbowServoPin1);  
  ElbowServo2.attach(ElbowServoPin2);
  GripperServo1.attach(GripperServoPin1);  
  GripperServo2.attach(GripperServoPin2);

  //Set initial positions
ShoulderServo1.write(60);
ShoulderServo2.write(60);
ElbowServo1.write(100);
ElbowServo2.write(120);
GripperServo1.write(90);
GripperServo2.write(90);
 delay (4000);
} 
 
void loop() 
{ 
  // sample pot-to-servo code
  //val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  // val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //myservo.write(val);                  // sets the servo position according to the scaled value
  //delay(15);                           // waits for the servo to get there

//test code

  
  ShoulderReading = analogRead(ShoulderPotPin); //0 to 1023
  int ShoulderAngle = map(ShoulderReading, 0, 1023, 60,135);                        //TWEAK THIS FORMULA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  int MirrorShoulderAngle = map(ShoulderReading, 0, 1023, 180, 60);
  ShoulderServo1.write(MirrorShoulderAngle); 
  ShoulderServo2.write(ShoulderAngle);
   delay(30);

  ElbowReading = analogRead(ElbowPotPin); //0 to 1023
  int ElbowAngle = map(ElbowReading, 0, 1023, 0, 150);                              //TWEAK THIS FORMULA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  int MirrorElbowAngle = map(ElbowReading, 0, 1023, 170,20);
  ElbowServo1.write(ElbowAngle);
  ElbowServo2.write(MirrorElbowAngle+20); //Odd-numbered motors are odd: they run backward
   delay(30);
   
  GripperReading = analogRead(GripperPotPin); //0 to 1023
  int GripperAngle = map(GripperReading, 0, 1023, 0, 100);                         //TWEAK THIS FORMULA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  int MirrorGripperAngle = map(GripperReading, 0, 1023, 190, 80);
  GripperServo1.write(GripperAngle);
  GripperServo2.write(MirrorGripperAngle);//Odd number, odd/reverse motion
   delay(30);
  
} 
