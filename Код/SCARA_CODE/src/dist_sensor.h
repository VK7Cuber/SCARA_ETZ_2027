#ifndef DIST_SENSOR_H
#define DIST_SENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_VL53L0X.h>

class DistSensor {
private:
    Adafruit_VL53L0X sensor;

public:
    DistSensor() {}

    bool init(){
        Wire1.begin();
        if (!sensor.begin(0x29, true, &Wire1)){
            return false;
        }
        return true;
    }

    int getDist(){
        VL53L0X_RangingMeasurementData_t measure;
        sensor.rangingTest(&measure, false);

        if (measure.RangeStatus != 4) {
            return measure.RangeMilliMeter;
        } else {
            return -1;
        }
    }

};


#endif