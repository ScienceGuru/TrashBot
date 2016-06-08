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
 * I tried to see how cheaply I could do this. So far, I'm at $21.00 
 * The 9g servos were super-cheap. 10 for $20.00
 * The structural/mechanical parts were mostly found around the house. 
 * I did purchase an acrylic ruler, and an acrylic folding stand a thrift shop. $1.00
 * 
 * I prototyped with wooden sticks -- like Popsicle sticks, but wider for spreading wax.
 * The "wrist", "hand", and gripper parts are scavenged from a broken RC helicopter.
 * 
 * I limited myself to 6 motors, because that eliminated the need for a shield.
 * I used a breadboard and other components that I already had. 
 * I did end up needing to buy potentiometers for control.
 * 
 * I powered the servos separately from the Arduino. I used a 4xAA battery pack to give me the full 6v for max torque on the servos.
 * 
 * Diagrams, schematics and pictures are included in the ZIP file I submitted. 
 * 
 * More info can also be found at github.com/ScienceGuru/TrashBot.
 * 
 * [ REMEMBER TO UPLOAD A SHORT VIDEO TO YOUTUBE!  Put URL here! ]
 */

 
int ShoulderPotPin = 0;  
int ShoulderServoPin1 = 9;
Servo ShoulderServo1; 
int ShoulderServoPin2 = 10;
Servo ShoulderServo2;

int ElbowPotPin = 1;
int ElbowServoPin1 = 11;
Servo ElbowServo1;
int ElbowServoPin2 = 12;
Servo ElbowServo2;

int WristPotPin = 3; //not used yet, maybe if I get a motor shield
int WristServoPinTilt; //give this a value if/when we use it
Servo WristServoTilt; // Tilt is probably more applicable than axial rotation

int GripperPotPin = 4;
int GripperServoPin1 = 13;
Servo GripperServo1;
int GripperServoPin2 = 14;
Servo GripperServo2;

 
void setup() 
{ 
  ShoulderServo1.attach(ShoulderServoPin1);  
  ShoulderServo2.attach(ShoulderServoPin2); 
  ElbowServo1.attach(ElbowServoPin1);  
  ElbowServo2.attach(ElbowServoPin2);
  GripperServo1.attach(GripperServoPin1);  
  GripperServo2.attach(GripperServoPin2);
 
} 
 
void loop() 
{ 
  // sample pot-to-servo code
  //int reading = analogRead(potPin);     // 0 to 1023
  //int angle = reading / 6;              // 0 to 180-ish
  //servo.write(angle);  

  int ShoulderReading = analogRead(ShoulderPotPin); //0 to 1023
  int ShoulderAngle = (ShoulderReading /20);                        //TWEAK THIS FORMULA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  ShoulderServo2.write(ShoulderAngle);
  ShoulderServo1.write(ShoulderAngle-180); //Odd-numbered motors are odd: they run backward

  int ElbowReading = analogRead(ElbowPotPin); //0 to 1023
  int ElbowAngle = (ElbowReading / 6);                              //TWEAK THIS FORMULA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  ElbowServo2.write(ElbowAngle);
  ElbowServo1.write(ElbowAngle-180); //Odd number, odd/reverse motion

  int GripperReading = analogRead(GripperPotPin); //0 to 1023
  int GripperAngle = (GripperReading / 12);                         //TWEAK THIS FORMULA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  GripperServo2.write(GripperAngle);
  GripperServo1.write(GripperAngle-180); //Odd number, odd/reverse motion
  
  
} 
