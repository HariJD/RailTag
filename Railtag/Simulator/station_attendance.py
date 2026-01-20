import paho.mqtt.client as mqtt
import random
import time

client = mqtt.Client("StationSimulator")
client.connect("test.mosquitto.org", 1883, 60)

while True:
    count = random.randint(100, 500)
    client.publish("railtag/station/attendance", str(count))
    print("Station Crowd:", count)
    time.sleep(10)
