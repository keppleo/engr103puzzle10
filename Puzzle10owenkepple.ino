#include <Adafruit_CircuitPlayground.h>

int score = 0;
int winningButton = 0;
bool waitingForInput = false;
bool gameActive = false;
bool gameWon = false;
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  randomSeed(analogRead(0));
}

void loop() {
  // Check slide switch to activate game
  bool switchState = CircuitPlayground.slideSwitch();

  if (!switchState) {
    // Reset game if switch is off
    score = 0;
    gameWon = false;
    waitingForInput = false;
    CircuitPlayground.clearPixels();
    return;
  }

  // If game has been won, do nothing until switch is toggled off
  if (gameWon) return;

  // Generate a new challenge if waitingForInput is false
  if (!waitingForInput) {
    winningButton = random(3); // 0 = left, 1 = right, 2 = sound
    CircuitPlayground.clearPixels();
    if(winningButton == 0){
    CircuitPlayground.setPixelColor(2, 0, 0, 255); // Blue hint right
    }
    else if(winningButton == 1){
      CircuitPlayground.setPixelColor(7, 0, 0, 255); // Blue hint left
    }
    else{
      CircuitPlayground.setPixelColor(4, 0, 0, 255); // Blue hint top
      CircuitPlayground.setPixelColor(5, 0, 0, 255); // Blue hint top
    }
    waitingForInput = true;
  }

  // Check player input
  if (waitingForInput) {
    float value = CircuitPlayground.mic.soundPressureLevel(10);
    if ((winningButton == 0 && CircuitPlayground.leftButton()) ||
        (winningButton == 1 && CircuitPlayground.rightButton()) ||
        (winningButton == 2 && value >= 80)){
      CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(880, 150);
      CircuitPlayground.setPixelColor(0, 0, 255, 0); // Green flash
      delay(200);
      waitingForInput = false;
      score++;
      Serial.print("Score: ");
      Serial.println(score);
    }
    if((winningButton == 1 && CircuitPlayground.leftButton()) ||
        (winningButton == 0 && CircuitPlayground.rightButton())) { //punishment for pressing wrong button
          CircuitPlayground.clearPixels();
      CircuitPlayground.playTone(320, 250);
      CircuitPlayground.setPixelColor(0, 255, 0, 0); // red flash
      delay(250);
      waitingForInput = false;
      score--;  //lose a scorepoint
      Serial.print("Score: ");
      Serial.println(score);
        }
    

    
  }

  // Check win condition
  if (score >= 10 && !gameWon) {
    gameWon = true;
    celebrateWin();
  }

  delay(50);
}



void celebrateWin() {
  for (int i = 0; i < 5; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
    CircuitPlayground.setPixelColor(9 - i, 0, 255, 0); //green leds light up symetrically and 
    CircuitPlayground.playTone(600 + i * 100, 150); // win tone plays
    delay(200);
  }
  CircuitPlayground.clearPixels();
  Serial.println("YOU WIN! Slide the switch off and back on to play again.");  //tried to get shaking to work to reset the game
}                                                                             // but it was resetting when it wasn't supposed to so the slide switch will work