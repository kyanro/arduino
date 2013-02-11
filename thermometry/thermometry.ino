/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
#define SOURCE_VOLT 5.0
#define TEMPERATURE_RANGE 186.0

float getTemp(float Vi){
  float 0.015168
  //説明書にのってた式
    Serial.println(Vi);
  return (Vi - 1.8528)/(-11.79 / 1000);
}

float getVi(int sensorValue, float Vmax){
  return (sensorValue / 1024.0) * Vmax;
}

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  float Vi = 0;
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  //温度センサからの入力電圧取得
  Vi = getVi(sensorValue, SOURCE_VOLT);
  
  //温度出力
  Serial.println(getTemp(Vi));
  delay(1000);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
//  delay(sensorValue);          
  // turn the ledPin off:        
//  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
//  delay(sensorValue);                  
}
