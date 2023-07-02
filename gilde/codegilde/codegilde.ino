// Player 1
const int p1InputPins[] = {2, 3, 4, 5, 6, 7, 8};
const int p1OutputPins[] = {22, 23, 24, 25, 26, 27, 28};
const int p1ResetPin = 16;
int p1Score = 0;

// Player 2
const int p2InputPins[] = {9, 10, 11, 12, 13, 14, 15};
const int p2OutputPins[] = {29, 30, 31, 32, 33, 34, 35};
const int p2ResetPin = 16;
int p2Score = 0;

void setup() {
  // Initialize input and output pins
  for (int i = 0; i < 7; i++) {
    pinMode(p1InputPins[i], INPUT_PULLUP);
    pinMode(p1OutputPins[i], OUTPUT);
    pinMode(p2InputPins[i], INPUT_PULLUP);
    pinMode(p2OutputPins[i], OUTPUT);
  }
  
  // Initialize reset button pin
  pinMode(p1ResetPin, INPUT_PULLUP);
  pinMode(p2ResetPin, INPUT_PULLUP);
  
  // Set initial scores to 0
  resetScores();
}

void loop() {
  // Check player 1 inputs
  for (int i = 0; i < 7; i++) {
    if (digitalRead(p1InputPins[i]) == LOW) {
      setPlayer1Score(i + 1);
    }
  }
  
  // Check player 2 inputs
  for (int i = 0; i < 7; i++) {
    if (digitalRead(p2InputPins[i]) == LOW) {
      setPlayer2Score(i + 1);
    }
  }
  
  // Check reset button for both players
  if (digitalRead(p1ResetPin) == LOW && digitalRead(p2ResetPin) == LOW) {
    resetScores();
  }
}

void setPlayer1Score(int score) {
  // Turn off all player 1 output pins
  for (int i = 0; i < 7; i++) {
    digitalWrite(p1OutputPins[i], HIGH);
  }
  
  // Set the corresponding player 1 output pin to LOW
  digitalWrite(p1OutputPins[score - 1], LOW);
  
  // Update player 1 score
  p1Score = score;
  
  // Turn off player 2 outputs
  for (int i = 0; i < 7; i++) {
    digitalWrite(p2OutputPins[i], HIGH);
  }
  
  // Set the corresponding player 2 output pin to LOW if player 2 has a score
  if (p2Score > 0) {
    digitalWrite(p2OutputPins[p2Score - 1], LOW);
  }
}

void setPlayer2Score(int score) {
  // Turn off all player 2 output pins
  for (int i = 0; i < 7; i++) {
    digitalWrite(p2OutputPins[i], HIGH);
  }
  
  // Set the corresponding player 2 output pin to LOW
  digitalWrite(p2OutputPins[score - 1], LOW);
  
  // Update player 2 score
  p2Score = score;
  
  // Turn off player 1 outputs
  for (int i = 0; i < 7; i++) {
    digitalWrite(p1OutputPins[i], HIGH);
  }
  
  // Set the corresponding player 1 output pin to LOW if player 1 has a score
  if (p1Score > 0) {
    digitalWrite(p1OutputPins[p1Score - 1], LOW);
  }
}

void resetScores() {
  // Reset player 1 score
  p1Score = 0;
  
  // Turn off all player 1 output pins
  for (int i = 0; i < 7; i++) {
    digitalWrite(p1OutputPins[i], HIGH);
  }
  
  // Reset player 2 score
  p2Score = 0;
  
  // Turn off all player 2 output pins
  for (int i = 0; i < 7; i++) {
    digitalWrite(p2OutputPins[i], HIGH);
  }
}
