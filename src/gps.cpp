// gps.cpp – PayloadX

#include "gps.h"

// Esempio base senza hardware reale
void initGPS() {
    // TODO: implement GPS initialization (e.g., using Adafruit_GPS)
}

void readGPSData(gpsData &data) {
    // TODO: implement GPS reading logic
    // Example placeholder values:
    data.lat = 44.4949;
    data.lng = 11.3426;
    data.alt = 100.0;
    data.speed = 0.0;
    data.heading = 0.0;
    data.sats = 4;
}
