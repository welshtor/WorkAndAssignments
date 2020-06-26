// Sometimes buttons are "flaky" and need "debouncing" as a means of filtering out accidental triggers
// This is like solving the "elevator button" problem

// Define LED pin aliases for CC3200-LAUNCHXL
// From Hardware datasheet: http://www.ti.com/lit/ug/swru372b/swru372b.pdf
#define RED_LED 29
#define YELLOW_LED 9
#define GREEN_LED 10
#define PUSH2 11

// variables will change:
int button_state = 0; // Use this to store the button status
int LED_state = HIGH;         // the current state of the output pin
int previous_state = LOW;   // The value of the input pin sample from the previous loop
long lastDebounceTime = 0; // Create a long to store the button press time in ms (the long avoids overflow)
long debounceDelay = 50; // This variable is the "spread" of time between button checks - play with it to see what it does!

void setup() {
  pinMode(GREEN_LED, OUTPUT);  // Initialize the pin as an output
  pinMode(PUSH2, INPUT_PULLUP); // Initialize pin as digital input. We configure a "pull up" resistor to make the input more stable
}

void loop() {
  int sample = digitalRead(PUSH2); // Read the switch value into a local variable

  if (sample != previous_state) { // Check if the current state differs from that of the previous sample
    lastDebounceTime = millis(); // Reset the "debouncing" timer
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) { // Check the sample to see if it's been consistent for longer than the debouncing (denoising) delay
    button_state = sample; // If it's been stable long enough, take the value as true
  }
  
  digitalWrite(GREEN_LED, button_state); // Set the LED state to match that of the button

  previous_state = sample; // Save the current sample as the previous for use at the next iteration of the loop
}
