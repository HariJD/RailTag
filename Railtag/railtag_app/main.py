import sys
from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine
import mqtt_client, fare_logic

class Backend:
    def boardTrain(self):
        mqtt_client.board()

    def exitTrain(self):
        mqtt_client.deboard()

    def calculateFare(self, src, dest):
        return fare_logic.calculate_fare(src, dest)

app = QGuiApplication(sys.argv)
engine = QQmlApplicationEngine()
engine.rootContext().setContextProperty("backend", Backend())
engine.load("ui/Main.qml")
sys.exit(app.exec())
