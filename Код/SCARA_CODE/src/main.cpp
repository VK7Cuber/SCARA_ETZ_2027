#include <Arduino.h>
#include <dist_sensor.h>

DistSensor sensor = DistSensor();
void setup() {
  Serial.begin(115200);

  while (!Serial) delay(10);
  Serial.println("Start");
  if (!sensor.init()){
    Serial.print("Error. Unconnected");
    while (true){
      delay(10);
    }
  }
}

void loop() {
  int dist = sensor.getDist();
  Serial.println(dist);
  delay(100);
}