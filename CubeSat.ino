// CubeSat.ino – PayloadX entry point

#include "src/imu.h"
#include "src/gps.h"
#include "src/radio.h"
#include "src/bms.h"

gpsData gps;
sensorData imu;
bmsData bms;

void setup() {
    Serial.begin(115200);
    initIMU();
    initGPS();
    initRadio();
}

void loop() {
    readIMUData(imu);
    readGPSData(gps);
    sendTelemetry(gps, imu);

    delay(1000); // 1s loop
}
