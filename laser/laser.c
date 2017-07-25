 int laserPin = 9;
  
 void setup() {
  pinMode (laserPin,OUTPUT); // designating pin 2 as output (we can use "Laser" instead of the pin # because we assigned "Laser" to pin 2 above)
}

void loop() {
  digitalWrite(laserPin,HIGH); // turning the laser on
  digitalWrite(laserPin,LOW); // turning the laser off
}
