// Variable to hold value from phototransistor
int sensorValue;
// Variable to hold lowest sensor value during calibration
int sensorLow = 1023;
// Variable to hold highest sensor value during calibration
int sensorHigh = 0;
// Onboard LED to indicate sensor has finished calibrating
const int ledPin = 13;
void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  digitalWrite(ledPin, HIGH); // Turn LED on to indicate calibration is starting
  while (millis() < 5000){ // Calibrate for the first 5 seconds after the program starts
    sensorValue = analogRead(A0); // Read the sensor on analog pin A0
    // Record the highest sensor value seen during calibration
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    // Record the lowest sensor value seen during calibration
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  // Trun LED off to show calibration is complete
  digitalWrite(ledPin, LOW);
}
void loop() {
  // Read the current sensor value
  sensorValue = analogRead(A0);
  // Map the calibrated sensor range to a frequency range (50-4000 Hz)
  // This determines pitch and sound
  int pitch =
    map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  // Play a tone on Piezo connected to pin 8 using the calculated pitch for 20 ms
  tone(8, pitch, 20);
  // Delay to keep sound stable 
  delay(10);
}
