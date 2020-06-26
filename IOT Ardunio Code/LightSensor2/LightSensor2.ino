#define RED_LED 29
#define YELLOW_LED 9
#define GREEN_LED 10 
#define ldrPin 2

void setup() {
 
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); 
  pinMode(YELLOW_LED, OUTPUT); 
  pinMode(GREEN_LED, OUTPUT); 
  pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
}

void loop() {

    float ldrStatus = analogRead(ldrPin);   //read the status of the LDR value
    Serial.println(ldrStatus);
  //check if the LDR status is <= 300
  //if it is, the LED is HIGH
   if (ldrStatus <= 10) {

     digitalWrite(RED_LED, HIGH);         //turn LED on
     digitalWrite(GREEN_LED, HIGH);         //turn LED on
     digitalWrite(YELLOW_LED, HIGH);         //turn LED on

    //Serial.println("LDR is DARK, LED is ON");
    
   }
  else {

    digitalWrite(RED_LED, LOW);          //turn LED off
    digitalWrite(YELLOW_LED, LOW);          //turn LED off
    digitalWrite(GREEN_LED, LOW);          //turn LED off

    Serial.println("---------------");
  }
} 
