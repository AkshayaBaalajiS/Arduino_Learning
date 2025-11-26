#include <WiFi.h>

const char* ssid = "testing";      // Replace with your WiFi name
const char* password = "12345679";  // Replace with your WiFi password

void setup() {
  Serial.begin(115200);

  Serial.println("\nStarting WiFi...");
  WiFi.mode(WIFI_AP);   // Set ESP32 as Station (client)
  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  Serial.print("Signal Strength (RSSI): ");
  Serial.println(WiFi.RSSI());
}

void loop() {
}
