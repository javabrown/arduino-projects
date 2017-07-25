 int laserPin = 9;
  
 void setup() {
  pinMode (laserPin,OUTPUT); // designating pin 9 as output
}

void loop() {
  digitalWrite(laserPin,HIGH); // turning the laser on
  digitalWrite(laserPin,LOW); // turning the laser off
}
