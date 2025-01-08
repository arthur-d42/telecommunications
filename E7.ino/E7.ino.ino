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