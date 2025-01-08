# 5a
Code is commented for function
```cpp
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
```
- [x] 5b: Implement the code in your own IDE.
- [x] 5c: Open the serial monitor (ctrl+shift+m), and set it to ”no line ending”. Send some data using the top line of the serial monitor.
# 5d: Why are you not receiving what you wrote? (e.g. G becomes 71)
It converts to an ASCII char so 'A' becomes 65 and newline is 10
# 5e: What happens if the serial monitor sends a line ending?
It outputs `received 10`
# 5f: Try changing the line Serial.print(incomingByte, DEC) to Serial.print((char)incomingByte). 
## What happens? 
It does not output `received 10`
## Why?
Because the serial monitor does not automatically send a line ending

