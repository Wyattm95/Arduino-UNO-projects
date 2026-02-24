// Initiates switchState to 0 (LOW)
int switchState = 0;
// Initiates pins 3, 4, and 5 to output / pin 2 to input
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}
// Reads input from pin 2
void loop() {
  switchState = digitalRead(2); // Read pin 2
  if (switchState == LOW){ // If switch connected to pin 2 is NOT pressed 
    digitalWrite(3, HIGH); // On
    digitalWrite(4, LOW); // Off
    digitalWrite(5, LOW); // Off
    delay(250); // Pause 1/4 sec
  }
  else { // Switch IS pressed
    digitalWrite(3, LOW); // Off
    digitalWrite(4, LOW); // Off
    digitalWrite(5, HIGH); // On
    delay(250); // Puase 1/4 sec
    digitalWrite(4, HIGH); // On
    digitalWrite(5, LOW); // Off
    delay(250); // Pause 1/4 sec
  }
}
