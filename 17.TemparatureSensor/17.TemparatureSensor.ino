
#include "DHT.h"

#define DHTPIN 4        // GPIO connected to DHT22
#define DHTTYPE DHT22   // DHT11 or DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT22 Sensor Initialized!");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  |  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  delay(2000); // DHT22 updates every ~2 seconds
}
