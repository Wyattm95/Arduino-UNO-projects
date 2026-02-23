/*****************************************************************************
 * Date - 02/23/26
 * Description:
 * This project programs the microcontroller to read the analog signal from a
 * TMP36 temperature sensor, convert the reading into a voltage value, and
 * calculate the corresponding temperature in degrees Celsius. Based on the
 * measured temperature, the microcontroller controls a series of LEDs to
 * visually indicate the current temperature range.
 *****************************************************************************/

// The temperature sensor's analog output is wired to analog pin A0
const int sensorPin = A0;

// Baseline temperature (20°C) used to define LED threshold levels
const float baselineTemp = 20.0;

void setup() {
  // Start serial communications to print debug info to Serial Monitor (9.6k bps)
  Serial.begin(9600); 
  // Configure pins 2, 3, 4 as outputs for LEDS.
  // Loop runs for pinNumber 2, 3, 4. Stops before 5
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    // LEDs begin loop off
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Read the senseor value at analog pin A0
  int sensorVal = analogRead(sensorPin);

  // Print the raw analog value
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Convert raw anaglog value to voltage 
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");

  // TMP36-stlye voltage to temperature (°C) conversion
  // TMP36 outputs 0.5v at 0°C and increases by 10mV per °C
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  /********************************
   ***      LED logic:          ***
   ********************************/

  // baselineTemp = 20.0°C      
  if(temperature < baselineTemp+2){
    // temperature below 22.0°C: all LEDs off
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
  
  }else if (temperature >= baselineTemp + 2 && temperature < baselineTemp +4){
    // temperature 22.0°C to < 24.0°C: LED on at pin 2 only
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    
  }else if (temperature >= baselineTemp + 4 && temperature < baselineTemp +6){
    // temperature 24.0°C to < 26.0°C: LEDs on at pins 2 and 3 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW); 
  
  }else if (temperature >= baselineTemp + 6){
    // temperature 26.0°C and up: all LEDs on
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
  }
  // delay 1 ms
  delay(1);
}
