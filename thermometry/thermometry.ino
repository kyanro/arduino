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

#define SOURCE_VOLT 5.0

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

float getTemp(float Vi){
  float temperature = 0;
  //説明書にのってた式
  temperature = -1481.96
               + sqrt(
                   2.1962 * pow(10, 6)
                 + (1.8639 - Vi) / (3.88 * pow(10, -6))
                 );
  return temperature;
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
  //あんまり急に温度変化しないように直近1000回の平均を出力とする
  float sumTemp = 0.0;
  int sumCount = 1000;
  int i = 0;
  
  float Vi = 0.0;

  digitalWrite(ledPin, HIGH);  

  for(i = 0; i < sumCount; i++){
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
   
    //温度センサからの入力電圧取得(温度センサの出力電圧)
    Vi = getVi(sensorValue, SOURCE_VOLT);
 
    sumTemp += getTemp(Vi);

    //温度出力
    delay(1);
  }
  Serial.println(sumTemp / sumCount);
}
