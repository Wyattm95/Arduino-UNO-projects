// Include Servo library to control the servo motor
#include <Servo.h>
// Create the Servo object to control the motor
Servo myServo;
// Analog pin connected to the potentiometer
int const potPin = A0;
// Variable to store the potentiometer reading
int potVal;
// Variable to store the mapped servo angle
int angle;
void setup() {
  // Attach the servo signal wire to digital pin 9
  myServo.attach(9);
  // Start serial communication 
  Serial.begin(9600);
}

void loop() {
  // Read the value from the potentiometer
  potVal = analogRead(potPin);
  // Print the raw potentiometer value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);
  // Conver the potentiometer value to the sero angle
  angle = map(potVal, 0, 1023, 0, 179);
  // Print the calculated servo angle 
  Serial.print(", angle: ");
  Serial.println(angle);
  // Move the servo to the mapped angle
  myServo.write(angle);
  // Short delay to allow servo to reach position
  delay(15);
}
