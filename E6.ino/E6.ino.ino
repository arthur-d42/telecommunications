int incomingByte = 0; // defines a variable as integer (not a constant)

const int delayTime = 1000;

const int ledA = 2;
const int ledB = 8;
const int ledC = 11;
const int ledD = 5;
const int ledE = 6;

void setup() {
	Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);

}
void loop() {
	if (Serial.available() > 0) { // checks if Serial connection is active
		incomingByte = Serial.read(); // If active reads

    char c;
    if (incomingByte >= 'a' && incomingByte <= 'z') {
      c = (char)incomingByte - 32;
    } else {
      c = (char)incomingByte;
    }

    Serial.print("I received: ");
		Serial.println(c); // and prints (converted to decimal)


    if (c == 'A'){
      digitalWrite(ledA, HIGH);
      delay(delayTime);
      digitalWrite(ledA, LOW);
    } else if (c == 'B'){
      digitalWrite(ledB, HIGH);
      delay(delayTime);
      digitalWrite(ledB, LOW);
    } else if (c == 'C'){
      digitalWrite(ledC, HIGH);
      delay(delayTime);
      digitalWrite(ledC, LOW);
    } else if (c == 'D'){
      digitalWrite(ledD, HIGH);
      delay(delayTime);
      digitalWrite(ledD, LOW);
    } else if (c == 'B'){
      digitalWrite(ledE, HIGH);
      delay(delayTime);
      digitalWrite(ledE, LOW);
    } else if (c >= 'A' && c <= 'Z') {
      Serial.print("other character");
      // Turn all LEDs on
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);

      delay(1000);  // Keep them on for 1 second

      // Turn all LEDs off
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
    } else {
      Serial.print("invalid input");
    }
    

	}


}