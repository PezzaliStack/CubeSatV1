# PayloadX – Firmware Architecture

Questo documento descrive l'architettura modulare del firmware PayloadX, derivato da CubeSat v1 di EdgeFlyte.

---

## 📦 Moduli principali

| Modulo     | Descrizione |
|------------|-------------|
| `imu.cpp` / `imu.h`     | Inizializza e legge dati da accelerometro, giroscopio, magnetometro |
| `gps.cpp` / `gps.h`     | Inizializza e raccoglie dati dal modulo GPS (latitudine, longitudine, altitudine, ecc.) |
| `radio.cpp` / `radio.h` | Gestisce la trasmissione via NRF24 |
| `bms.cpp` / `bms.h`     | Decodifica i messaggi provenienti dal Battery Management System |
| `main.cpp`              | Funzione principale: legge, elabora e trasmette i dati in loop |
| `CubeSat.ino`           | Entry point per Arduino IDE: include i moduli e gestisce la logica |

---

## 🔁 Flusso dati semplificato

```mermaid
graph TD;
  A[setup()] --> B[initIMU()]
  A --> C[initGPS()]
  A --> D[initRadio()]

  loop[loop()] --> E[readIMUData()]
  loop --> F[readGPSData()]
  loop --> G[sendTelemetry()]

![PayloadX – System Architecture](./architettura.png)
