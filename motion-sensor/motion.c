const int ledPin= 13;  //led output pin
const int inputPin= 8; //sensor input pin.

void setup(){
	pinMode(ledPin, OUTPUT);
	pinMode(inputPin, INPUT);
}

void loop(){
	int value= digitalRead(inputPin);

	if (value == HIGH)
	{
	digitalWrite(ledPin, HIGH);
	delay(10000);
	digitalWrite(ledPin, LOW);
	}
	else
	{
	digitalWrite(ledPin, LOW);
	}
}
