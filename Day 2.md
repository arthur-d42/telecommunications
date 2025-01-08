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

# 6a: What is a char? How many bits does one use?
A char represents an ASCII character with 8 bits
# 6b: What is the resulting character stored in the variable mychar ?
```cpp
char mychar = ’4’; // 52
int val = mychar-’0’; // 52 - 48 = 4
mychar = (char)(val+’A’-1) // 4+65-1 = 68 = D
```
Value is 68 or D
# 6c: Make a program that lights an LED depending on what character has been send to the Uno
- [x] The LEDs should represent the letters a, b, c, d and e. One LED for each letter.
- [x] When sending one of the first five letters of the alphabet (case invariant) the corresponding LED must
light up.
- [x] All other characters should turn off all five LEDs.
- [x] Lamps should only turn off if an unknown character is sent.
```cpp
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
```

# 7a: What is an RGB value? Why does it use the interval 0-255?
RGB value is a tuple of three inteeer
# 7b: What does the function Serial.parseInt() do ?
# 7c: Parse values from the serial monitor
- [x] Send a string of three comma separated values from the serial monitor e.g. 200,100,40
- [x] Read these values as integers (not a string), you can use Serial.parseInt()
# 7d: Use the values the fade the RGB LED
```cpp
int incomingByte = 0;
const int delayTime = 1000;
const int ledR = 13;
const int ledG = 9;
const int ledB = 11;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
    Serial.begin(9600);
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
    
    // Initially turn off all LEDs (common anode)
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, HIGH);

}

void loop() {

    if (Serial.available() > 0) {
        redValue = Serial.parseInt();
        // comma
        Serial.read();
        
        greenValue = Serial.parseInt();
        Serial.read();
        
        blueValue = Serial.parseInt();
        
        while (Serial.available() > 0) {
            char c = Serial.read();
            if (c == '\n') break;
        }

        Serial.print("Setting RGB to: ");
        Serial.print(redValue);
        Serial.print(",");
        Serial.print(greenValue);
        Serial.print(",");
        Serial.println(blueValue);
        
        // common anode, invert the values
        // 0 = full on, 255 = full off
        analogWrite(ledR, 255 - redValue);
        analogWrite(ledG, 255 - greenValue);
        analogWrite(ledB, 255 - blueValue);
    }
}
```


