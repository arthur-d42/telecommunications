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

        Serial.print(analogRead(A1));
        Serial.print("\n");
        delay(100);
        // 0 = full on, 255 = full off
        // analogWrite(ledR, 255 - redValue);
        // analogWrite(ledG, 255 - greenValue);
        // analogWrite(ledB, 255 - blueValue);

}