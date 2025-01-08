int incomingByte = 0; // defines a variable as integer (not a constant)
void setup() {
	Serial.begin(9600);
}
void loop() {
	if (Serial.available() > 0) { // checks if Serial connection is active
		incomingByte = Serial.read(); // If active reads
		Serial.print("I received: ");
		Serial.println(incomingByte, DEC); // and prints (converted to decimal)
	}
}