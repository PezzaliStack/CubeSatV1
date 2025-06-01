// radio.cpp – PayloadX

#include "radio.h"
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 7
#define CSN_PIN 8
RF24 radio(CE_PIN, CSN_PIN);

void initRadio() {
    if (!radio.begin()) {
        // TODO: handle error
        return;
    }
    radio.setPALevel(RF24_PA_LOW);
    radio.setChannel(62);
    radio.setPayloadSize(32);
    radio.setDataRate(RF24_1MBPS);
    radio.openWritingPipe("Node1");
}

void sendTelemetry(const gpsData &gps, const sensorData &imu) {
    char packet[32];
    snprintf(packet, sizeof(packet), "#T,%.5f,%.5f,%.2f,%.2f,%.2f,%.2f",
             gps.lat, gps.lng,
             imu.ax, imu.ay, imu.az,
             gps.alt);

    radio.write(&packet, sizeof(packet));
}
