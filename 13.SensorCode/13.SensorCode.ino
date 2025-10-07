// Include the DHT sensor library (Adafruit)
// This library has all the functions to read temperature and humidity easily
#include "DHT.h"

// Define the pin where the DHT22 data pin is connected
#define DHTPIN 4  

// Define the type of DHT sensor (DHT22 / AM2302)
#define DHTTYPE DHT22  

// Create a DHT object with the pin and sensor type
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication for debugging
  // 115200 baud rate is standard for ESP32
  Serial.begin(115200);  

  Serial.println("DHT22 Temperature & Humidity Sensor Test");

  // Start the DHT sensor
  // Must call begin() in setup() before reading values
  dht.begin();  
}

void loop() {
  // Wait a few seconds between measurements
  // DHT22 requires ~2 seconds between reads
  delay(2000);  

  // Read humidity (in %)
  float humidity = dht.readHumidity();  

  // Read temperature in Celsius
  float temperature = dht.readTemperature();  

  // Read temperature in Fahrenheit
  float temperatureF = dht.readTemperature(true);  

  // Check if any reading failed and exit early
  // NaN (Not a Number) indicates sensor error
  if (isnan(humidity) || isnan(temperature) || isnan(temperatureF)) {
    Serial.println("Failed to read from DHT sensor!");
    return; // Skip this loop iteration
  }

  // Print humidity to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);  // Prints value
  Serial.println(" %");    // Unit

  // Print temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Print temperature in Fahrenheit
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  // Optional: add a small delay to avoid flooding Serial Monitor
  delay(1000);  
}
