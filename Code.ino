#define STEP_PIN 3       // Step pin for controlling steps
#define DIR_PIN 4        // Direction pin for controlling direction
#define ENABLE_PIN 5     // Enable pin to enable the driver (optional)
#define BUTTON_CW_PIN 7  // Push button for clockwise rotation
#define BUTTON_CCW_PIN 8 // Push button for counterclockwise rotation

void setup() {
  // Set the pins as OUTPUT for the stepper driver
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  
  // Set the pins for push buttons as INPUT_PULLUP
  pinMode(BUTTON_CW_PIN, INPUT_PULLUP); // Use internal pull-up resistor
  pinMode(BUTTON_CCW_PIN, INPUT_PULLUP); // Use internal pull-up resistor
  
  // Enable the stepper driver
  digitalWrite(ENABLE_PIN, LOW);  // Enable stepper driver (LOW typically enables)
}

void loop() {
  // Check if the clockwise button is pressed
  if (digitalRead(BUTTON_CW_PIN) == LOW) {
    rotateClockwise();
  }
  
  // Check if the counterclockwise button is pressed
  if (digitalRead(BUTTON_CCW_PIN) == LOW) {
    rotateCounterClockwise();
  }
}

// Function to rotate stepper motor clockwise
void rotateClockwise() {
  digitalWrite(DIR_PIN, HIGH);  // Set direction to clockwise
  stepMotor();  // Perform a step
}

// Function to rotate stepper motor counterclockwise
void rotateCounterClockwise() {
  digitalWrite(DIR_PIN, LOW);   // Set direction to counterclockwise
  stepMotor();  // Perform a step
}

// Function to step the motor
void stepMotor() {
  digitalWrite(STEP_PIN, HIGH);  // Generate a pulse
  delayMicroseconds(1000);       // Adjust delay to control speed
  digitalWrite(STEP_PIN, LOW);   // End pulse
  delayMicroseconds(1000);       // Adjust delay to control speed
}
