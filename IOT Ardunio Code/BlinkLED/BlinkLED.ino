// Define LED pin aliases for CC3200-LAUNCHXL
// From Hardware datasheet: http://www.ti.com/lit/ug/swru372b/swru372b.pdf
#define RED_LED 29
#define YELLOW_LED 9
#define GREEN_LED 10

// Setup runs once when'RESET' is pressed or when power is applied
void setup() {                
  pinMode(RED_LED, OUTPUT); // Configure the red LED as a digital output
}

void loop() { // Loop repeats indefinitely
  digitalWrite(RED_LED, HIGH);   // Set the voltage level on the RED_LED pin to HIGH
  delay(1000);               // Wait for 1,000ms (approximately)
  digitalWrite(RED_LED, LOW); // Set the voltage level on the RED_LED pin to LOW   
  delay(1000);               // Wait for 1,000ms (approximately)
}
