
#include <NewPing.h>
#include <Servo.h> 

//Setup the Ultrasonic Sensor
#define TRIG_PIN 12
#define ECHO_PIN 13 
#define MAX_DISTANCE 200
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

  /*int enR = 10; //Right Motor Speed
  int enL = 11;  //Left Motor Speed

  int RFwd = 4;  //Right Motor Forward
  int RBwd = 3;  //Right Motor Backward
  int LFwd = 6; //Left Motor Forward
  int LBwd = 5; //Left Motor Backward
*/


  // Motor A pins (enableA = enable motor, pinA1 = forward, pinA2 = backward)
  int enL = 11;
  int LFwd = 6;
  int LBwd = 5;
  
  //Motor B pins (enabledB = enable motor, pinB2 = forward, pinB2 = backward)
  int enR = 10;
  int RFwd = 4;
  int RBwd = 3;

  int maxSpeed = 150;

  Servo myservo;
  int servoPin = 9;   

  boolean goesForward=false;
  int distance = 100;

void setup() {
   
  Serial.begin(9600);
     //Initialize the servo

  myservo.attach(servoPin);  
  myservo.write(90); 
  delay(500);
  Serial.println("Servo initialized");

  //Stabilize the distance
//  for(int i=1; i=6; i++){
  distance = readPing();
  delay(50);
  Serial.println("Ping stabilized");
    distance = readPing();
  delay(50);
  Serial.println("Ping stabilized");
    distance = readPing();
  delay(50);
  Serial.println("Ping stabilized");
    distance = readPing();
  delay(50);
  Serial.println("Ping stabilized");
    distance = readPing();
  delay(50);
  Serial.println("Ping stabilized");
    distance = readPing();
  delay(50);
  Serial.println("Ping stabilized");
//  }

  // Set the Motor Pins for OUTPUT
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(RFwd, OUTPUT);
  pinMode(RBwd, OUTPUT);
  pinMode(LFwd, OUTPUT);
  pinMode(LBwd, OUTPUT);

  digitalWrite(enL, HIGH);
  digitalWrite(enR, HIGH);
   
  Serial.println("Motor Pins set for output");
}

void stop(){
  digitalWrite(RFwd, LOW);
  digitalWrite(RBwd, LOW);
  digitalWrite(LFwd, LOW);
  digitalWrite(LBwd, LOW);  
}

void goForward(){
   digitalWrite(LBwd, LOW);
   digitalWrite(LFwd, HIGH);

   digitalWrite(RFwd, HIGH);
   digitalWrite(RBwd, LOW);
 
  /*if(!goesForward)
   {
    Serial.print ("In the goesForward routine. goesForward = ");
    Serial.println (goesForward);
    goesForward=true;
    digitalWrite(RBwd, LOW);  //Write the Low's first to minimize delay between writing the High's
    digitalWrite(LBwd, LOW);  

    for (int speed = 100; speed <=maxSpeed; speed += 20){
      analogWrite(enR,speed-9);
      analogWrite(enL, speed);

      digitalWrite(RFwd, HIGH);
      digitalWrite(LFwd, HIGH);

      delay(100);
    }

  delay(50);
  }*/
}

void goBackward(){
  goesForward=false;
  /*digitalWrite(RFwd, LOW);  //Write the Low's first to minimize delay between writing the High's
  digitalWrite(LFwd, LOW);

  for (int speed = 100; speed <=maxSpeed; speed += 20){
  analogWrite(enR, speed);
  analogWrite(enL, speed);
  
  digitalWrite(RBwd, HIGH);
  digitalWrite(LBwd, HIGH);  
  delay(5);
  }*/

   digitalWrite(LBwd, HIGH);
   digitalWrite(LFwd, LOW);

   digitalWrite(RFwd, LOW);
   digitalWrite(RBwd, HIGH);

  delay(750);
  stop();
} 

void turnRight(){
  //analogWrite(enR, 0);
  //analogWrite(enL, 150);
  digitalWrite(RBwd, LOW);
  digitalWrite(LBwd, LOW);
  digitalWrite(RFwd, LOW);
  digitalWrite(LFwd, HIGH);
   delay(600);
   stop();
}

void turnLeft(){
  //analogWrite(enR, 150);
  //analogWrite(enL, 0);
  digitalWrite(RBwd, LOW);
  digitalWrite(LBwd, LOW);
  digitalWrite(LFwd, LOW);
  digitalWrite(RFwd, HIGH);
   delay(600);
   stop();
}


int lookRight()
{
    myservo.write(15); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
}

int lookLeft()
{
    myservo.write(175); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void loop() {
 int distanceR = 0;
 int distanceL = 0;
 delay(40);

 Serial.print ("Distance = ");
 Serial.print (distance);
 Serial.println(" cm");
 
 if(distance<=50)
 {
  Serial.println("Too close, looking for another path");
  stop();
  delay(100);
  goBackward();
  stop();

  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    Serial.print ("Turn Right");
    turnRight();
    stop();
  }else
  {
    Serial.print ("Turn Left");
    turnLeft();
    stop();
  }
 }else
 {
  Serial.print("All clear, move forward");
  goForward();
 }
 distance = readPing();
}
