// LED output pin assignments (PWM pins for color mixing)
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

// Analog input pins from the coor sensor
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

// Variables to store LED brightness values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

// Variables to store raw sensor reading
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // Start serial communications to print debug info to Serial Monitor (9.6k bps)
  Serial.begin(9600);

  //Set LED pins as outputs
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // Read analog values from each sensor
  redSensorValue = analogRead(redSensorPin);
  delay(5); // Short delay to stabilize readings
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  // Print raw sensor values to Serial Monitor
  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);

  // Convert 10-bit analog values to 8-bit PWM values
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  // Print mapped values used for LED brightness
  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue");
  Serial.println(blueValue);

  // Output PWM signals to the RGB LED
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
