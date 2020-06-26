// Define LED pin aliases for CC3200-LAUNCHXL
// From Hardware datasheet: http://www.ti.com/lit/ug/swru372b/swru372b.pdf
#define RED_LED 29
#define YELLOW_LED 9
#define GREEN_LED 10

void setup()  { 


} 

void loop()  { 

  // We don't need to initialize anything here since the pin definition is implicit in the later call to analogWrite
  // Fade from minimum to maximum (0% to 100% duty cycle)
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { // Increment the fadeValue from 0 to 255 in steps of 5
    analogWrite(RED_LED, fadeValue); // Write to the RED_LED pin as an "analog value" -- in reality, the pin will generate a steady square wave of the specified duty cycle at ~500Hz
    delay(10); // Wait 10ms between steps
  } 

    // We don't need to initialize anything here since the pin definition is implicit in the later call to analogWrite
  // Fade from max to in (0% to 100% duty cycle)
  for(int fadeValue = 255 ; fadeValue <= 255; fadeValue -=5) { // Increment the fadeValue from 0 to 255 in steps of 5
    analogWrite(RED_LED, fadeValue); // Write to the RED_LED pin as an "analog value" -- in reality, the pin will generate a steady square wave of the specified duty cycle at ~500Hz
    delay(10); // Wait 10ms between steps
  } 
  
}
