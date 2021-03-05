#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* server = "api.thingspeak.com";
String apiKey = "BY65CAJORV3WM7YO";
WiFiClient client;
long myChannelNumber = 1312674; //channel number for connecting channel in thingspeak
const char myWriteAPIKey[] = "BY65CAJORV3WM7YO";  //apikey for my channel

const char* ssid = "Roshan_ClassicTech"; 
const char* password = "classic@#!";
char data;

void setup() {

  Serial.begin(9600);
  delay(4);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println("Server started");
  ThingSpeak.begin(client);
}

bool check = true;
void loop() {
  if (Serial.available()) {
    String val = Serial.readStringUntil('\n');
    data = val[0];
  }
  Serial.print("Serial ");
  Serial.println(data);
  delay(1000);
  if (data) {
    if (client.connected())
    {
      client.stop();
    }
  ThingSpeak.writeField(myChannelNumber, 1, data, myWriteAPIKey);
    client.stop();
  }
}
