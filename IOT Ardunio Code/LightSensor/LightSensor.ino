// This code will interfere with the red and yellow LED's due to pin sharing
#include <Wire.h>
#include <BMA222.h>

#define NUM_READINGS 700 // The number of reacings to keep track of in the moving average - more numbers will better-smooth the signal, but will reduce the response speed
#define RED_LED 29

int readingsX[NUM_READINGS];      // the readings from the analog input
int readingsY[NUM_READINGS];
int readingsZ[NUM_READINGS];
int readingIndex = 0;      // the index of the current reading

int totalX = 0;                  // the running total
int totalY = 0;
int totalZ = 0;

int averageX = 0;               
int averageY = 0;
int averageZ = 0;

int threshold = 40;
int xdif = 0,ydif=0,zdif=0;

BMA222 myAccelerometer; // Placeholder object for the BMA222 accelerometer

void setup()
{
  Serial.begin(115200); // Initialize the serial port at 115,200bps (8-N-1 unless otherwise specified)
  
  myAccelerometer.begin(); // Instantiate the sensor object
  uint8_t chipID = myAccelerometer.chipID(); // Capture the accelerometer ID
  Serial.print("chipID: "); Serial.println(chipID); // Print the sensor ID
  pinMode(RED_LED, OUTPUT);
  for (int thisReading = 0; thisReading < NUM_READINGS; thisReading++) { readingsX[thisReading] = 0; } // Initialize all sensor readings to 0 at the start
  for (int thisReading = 0; thisReading < NUM_READINGS; thisReading++) { readingsY[thisReading] = 0; }
  for (int thisReading = 0; thisReading < NUM_READINGS; thisReading++) { readingsZ[thisReading] = 0; }
}

void loop() {
  //Read all axis data
  int8_t datax = myAccelerometer.readXData(); // Use the BMA222 library to pull the X data
  int8_t datay = myAccelerometer.readYData(); // Use the BMA222 library to pull the X data
  int8_t dataz = myAccelerometer.readZData(); // Use the BMA222 library to pull the X data

  //Add and total for each axis
  totalX = totalX - readingsX[readingIndex]; // Subtract the most recent reading from the total
  readingsX[readingIndex] = datax; // Add the latest reading to the array
  totalX = totalX + readingsX[readingIndex]; // Add the reading to the total

  totalY = totalY - readingsY[readingIndex]; // Subtract the most recent reading from the total
  readingsY[readingIndex] = datay; // Add the latest reading to the array
  totalY = totalY + readingsY[readingIndex]; // Add the reading to the total

  totalZ = totalZ - readingsZ[readingIndex]; // Subtract the most recent reading from the total
  readingsZ[readingIndex] = dataz; // Add the latest reading to the array
  totalZ = totalZ + readingsZ[readingIndex]; // Add the reading to the total
  
  readingIndex = readingIndex + 1; // Move the index to the next location in the array

  if (readingIndex >= NUM_READINGS) { readingIndex = 0; } // When the array is full, wrap around again to the start and push out the oldest readings
  averageX = totalX / NUM_READINGS; // Calculate the average over the whole array
  averageY = totalY / NUM_READINGS; 
  averageZ = totalZ / NUM_READINGS; 
  
  xdif =  abs(abs(datax) - abs(averageX));
  ydif = abs(abs(datay) - abs(averageY));
  zdif =  abs(abs(dataz) - abs(averageZ));
  int8_t maxDif = max(max(xdif,ydif),zdif);
  
  if(maxDif >threshold)
  {
    digitalWrite(RED_LED, HIGH);   // Set the voltage level on the RED_LED pin to HIGH
  }
  else
  {
     digitalWrite(RED_LED, LOW);
  }
  Serial.println("MaxDif: ");
  Serial.println(maxDif); 
  delay(5); // Pause a bit between readings to improve temporal stability
}
