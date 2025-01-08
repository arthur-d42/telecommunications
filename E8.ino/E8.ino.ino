int incomingByte = 0;
const int delayTime = 1000;
const int ledR = 13;
const int ledG = 9;
const int ledB = 11;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

float voltage = 0;

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
        voltage = analogRead(A1) * (5.0 / 1023.0);
        Serial.print(voltage);
        Serial.print("V\n");
        blueValue = map(analogRead(A1), 0, 1023, 0, 255);
        analogWrite(ledR, 0);
        analogWrite(ledB, 255 - blueValue);
        delay(100);


}