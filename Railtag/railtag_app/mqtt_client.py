import paho.mqtt.client as mqtt

BROKER = "test.mosquitto.org"
client = mqtt.Client("RailTag_App")
client.connect(BROKER, 1883, 60)

def board():
    client.publish("railtag/board", "1")

def deboard():
    client.publish("railtag/deboard", "1")
