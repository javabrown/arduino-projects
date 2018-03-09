    int relayPin = 7;
    int sensorPin = 2;
    
    int val = 0; 
    int pirState = LOW;
    
    void setup() {
      pinMode(relayPin, OUTPUT);
      pinMode(sensorPin, INPUT); 
      
      //digitalWrite(relayPin, LOW);
      Serial.begin(9600);
    }
    
    void loop() {
      val = digitalRead(sensorPin);
      //Serial.println(HIGH); 
      
      if (val == HIGH) {
          digitalWrite(relayPin, HIGH);
          
          if (pirState == LOW) {
            Serial.println("Motion detected!"); 
            pirState = HIGH;
          }
      }
      else {
          digitalWrite(relayPin, LOW); // turn LED OFF
          
          if (pirState == HIGH){
            Serial.println("Motion ended!");
            pirState = LOW;
          }
      }
      
      //delay(3000);
      
      digitalWrite(relayPin, LOW);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      delay(3000);
    }

    
