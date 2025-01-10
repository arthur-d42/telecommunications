/**
 * @mainpage LED Catching Game
 * @brief Arduino game where you catch the middle LED
 * 
 * Check out the full code here: @ref e12.cpp
 */

/**
 * @file e12.cpp
 * @brief An LED catching game using Arduino and LCD display
 * @author S214809, S225044
 * @date Today
 * 
 * The game gets harder as you play and the LEDs move faster. Try to get 10 
 */


/**
 * @brief An LED catching game using Arduino and LCD display
 * @author S214809, S225044
 * 
 * The game gets harder as you play and the LEDs move faster. Try to get 10 
 */

#include <LiquidCrystal_I2C.h>

/// @brief LCD display object - connects to the I2C display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int currentLED = 0;      ///< Keeps track of which LED is lit up rn
int hitCounter = 0;      ///< Counts how many times player hit the middle LED
int missCounter = 0;     ///< Counts how many times player messed up
bool gameRunning = true; ///< Tells if game is still going
int delayTime = 1000;    ///< Basic delay time (not really used but keeping it)
unsigned long ledInterval = 500;    ///< How fast LEDs change (in millisecs)
unsigned long previousMillis = 0;   ///< Last time we updated LED
bool ledState = false;   ///< Current LED state (on/off)

/**
 * @brief Sets up all the stuff we need when game starts
 * 
 * Does these things:
 * - Sets up all the LED pins as outputs (pins 8-12)
 * - Sets up button with pullup resistor (pin 13)
 * - Initializes the LCD and shows start message
 * - Starts serial comunication (might be useful for debugging)
 */
void setup() {


  //LED
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);


  //Button
  pinMode(13, INPUT_PULLUP);


  //Initial setup of game
  lcd.init();
  lcd.backlight();
  lcd.print("Catch the LED!");
  delay(2000);
  previousMillis = millis();
  lcd.clear();
  Serial.begin(9600);
}

/**
 * @brief Main game loop that runs forever
 * 
 * Checks if game is running, then:
 * - Updates LED position based on timing
 * - Checks if player pressed button
 * - Moves to next LED position
 */
void loop() {
  if (gameRunning) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= ledInterval) {
      previousMillis = currentMillis;
      lightUpLED(currentLED);
      checkButtonPress();
      currentLED = (currentLED + 1) % 5;
    }
  }

}

/**
 * @brief Turns on one LED and turns off all others
 * @param ledIndex Which LED to turn on (0-4)
 * 
 * Makes sure only one LED is on at a time by turning all off first
 */
void lightUpLED(int ledIndex) {
  for (int i = 8; i <= 12; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(8 + ledIndex, HIGH);
}

/**
 * @brief Checks if player pressed button and handles what happens
 * 
 * If button pressed:
 * - Checks if middle LED was lit (thats a hit!)
 * - Updates score on LCD
 * - Makes game faster if player got a hit
 * - Shows miss message if player missed
 * - Ends game if player got 10 hits
 */
void checkButtonPress() {
 if (digitalRead(13) == LOW) {
    if (currentLED == 2) {
      hitCounter++;
      lcd.clear();
      lcd.print("Hit: ");
      lcd.print(hitCounter);
      increaseDifficulty();
    } else {
      missCounter++;
      lcd.clear();
      lcd.print("Miss!");
      lcd.setCursor(0, 1);
      lcd.print("Misses: ");
      lcd.print(missCounter);
    }


    if (hitCounter >= 10) {
      playerHits();
    }
  }
}

/**
 * @brief Makes the game harder by speeding up LEDs
 * 
 * Decreases interval between LED changes by 50ms
 * Won't go below 100ms 
 */
void increaseDifficulty() {
  if (ledInterval > 100){
    ledInterval -= 50;
  }
}

/**
 * @brief Called when player gets 10 hits and wins
 * 
 * Shows win message and starts victory celebration!
 */
void playerHits() {
  gameRunning = false;
  lcd.clear();
  lcd.print("You Win!");
  playerWins();
}

/**
 * @brief Does victory celebration with random LED pattern
 * 
 * Makes LEDs do a blink thing 20 times
 * then shows game over message
 */
void playerWins() {
  for (int i = 0; i < 20; i++){
    int randomLED = random(8, 13);
    digitalWrite(randomLED, HIGH);
    delay(100);
    digitalWrite(randomLED, LOW);
  }
  lcd.clear();
  lcd.print("Game Over");
}
