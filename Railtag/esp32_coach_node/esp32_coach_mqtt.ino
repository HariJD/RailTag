#include <WiFi.h>
#include <PubSubClient.h>

/* WiFi Credentials */
const char* ssid = "RailTag_WiFi";
const char* password = "12345678";

/* MQTT */
const char* broker = "test.mosquitto.org";
const char* coachID = "COACH_A1";

WiFiClient espClient;
PubSubClient client(espClient);

int passengerCount = 0;

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (String(topic) == "railtag/board") {
    passengerCount++;
  }
  else if (String(topic) == "railtag/deboard") {
    passengerCount--;
    if (passengerCount < 0) passengerCount = 0;
  }

  String crowdStatus;
  if (passengerCount > 40) crowdStatus = "FULL";
  else if (passengerCount > 20) crowdStatus = "MEDIUM";
  else crowdStatus = "EMPTY";

  client.publish("railtag/crowd", crowdStatus.c_str());
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  client.setServer(broker, 1883);
  client.setCallback(mqttCallback);

  while (!client.connected()) {
    client.connect(coachID);
    delay(500);
  }

  client.subscribe("railtag/board");
  client.subscribe("railtag/deboard");
}

void loop() {
  client.loop();
}
