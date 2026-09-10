#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

// =========================
// DHT22
// =========================

#define DHTPIN D4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// =========================
// WiFi
// =========================

const char* ssid = "your_ssid";
const char* password = "*********";

// =========================
// ThingSpeak
// =========================

unsigned long myChannelNumber = *********;
const char* myWriteAPIKey = "***************";

WiFiClient client;

// =========================
// SETUP
// =========================

void setup()
{
  Serial.begin(115200);

  dht.begin();

  Serial.println();
  Serial.println("Starting Weather Station...");

  // Connect to WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start ThingSpeak
  ThingSpeak.begin(client);
}


// =========================
// LOOP
// =========================

void loop()
{
  // Read DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check sensor
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Failed to read DHT22!");
    delay(2000);
    return;
  }

  // Display readings
  Serial.println("--------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");


  // =========================
  // Bad weather detection
  // =========================

  if (temperature > 35)
  {
    Serial.println("WARNING: High Temperature!");
  }

  if (temperature < 10)
  {
    Serial.println("WARNING: Low Temperature!");
  }

  if (humidity > 85)
  {
    Serial.println("WARNING: High Humidity!");
  }


  // =========================
  // Send to ThingSpeak
  // =========================

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int response = ThingSpeak.writeFields(
    myChannelNumber,
    myWriteAPIKey
  );

  if (response == 200)
  {
    Serial.println("ThingSpeak update successful!");
  }
  else
  {
    Serial.print("ThingSpeak error: ");
    Serial.println(response);
  }

  // ThingSpeak requires at least ~15 seconds between updates
  delay(20000);
}