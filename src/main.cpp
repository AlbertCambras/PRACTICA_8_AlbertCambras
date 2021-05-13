#include <Arduino.h>

void setup() {
Serial.begin(9600);
Serial2.begin(9600);
  Serial.write("Inicializando...");
}

void loop() {

  if(Serial.available()){
    Serial2.write(Serial.read());
    delay(10);
    if(Serial2.available()){
      Serial.write(Serial2.read());
    }
  }
}