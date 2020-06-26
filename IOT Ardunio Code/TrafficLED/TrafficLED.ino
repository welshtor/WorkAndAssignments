//Create a Traffic Light Simulation
//
#define RED_LED 29
#define YELLOW_LED 9
#define GREEN_LED 10 
void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT); // Configure the red LED as a digital output
  pinMode(YELLOW_LED, OUTPUT); // Configure the yellow LED as a digital output
  pinMode(GREEN_LED, OUTPUT); // Configure the green LED as a digital output
}

void loop() { //repeats forever
  digitalWrite(RED_LED, HIGH);   // Set the voltage level on the RED_LED pin to HIGH
  digitalWrite(GREEN_LED, LOW); // Set the voltage level on the GREEN_LED pin to LOW   
  digitalWrite(YELLOW_LED, LOW); // Set the voltage level on the YELLOW_LED pin to LOW   

  delay(4500);               // Wait for 1,000ms (approximately)
  
  digitalWrite(RED_LED, LOW); // Set the voltage level on the RED_LED pin to LOW   
  delay(200);              

  
  digitalWrite(GREEN_LED, HIGH);   // Set the voltage level on the GREEN_LED pin to HIGH
  digitalWrite(YELLOW_LED, LOW); // Set the voltage level on the YELLOW_LED pin to LOW   
  digitalWrite(RED_LED, LOW); // Set the voltage level on the RED_LED pin to LOW   
  
  delay(6000);               // Wait for 1,000ms (approximately)
  
  digitalWrite(GREEN_LED, LOW); // Set the voltage level on the GREEN_LED pin to LOW   
  delay(200);               

  digitalWrite(YELLOW_LED, HIGH);   // Set the voltage level on the YELLOW_LED pin to HIGH
  digitalWrite(GREEN_LED, LOW); // Set the voltage level on the GREEN_LED pin to LOW   
  digitalWrite(RED_LED, LOW); // Set the voltage level on the RED_LED pin to LOW   
  
  delay(2000);               // Wait for 1,000ms (approximately)
  
  digitalWrite(YELLOW_LED, LOW); // Set the voltage level on the YELLOW_LED pin to LOW   
  delay(200);               
}
