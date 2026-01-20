import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 360
    height: 600
    title: "RailTag"

    Column {
        anchors.centerIn: parent
        spacing: 16

        Button {
            text: "Board Train"
            onClicked: backend.boardTrain()
        }

        ComboBox {
            id: dest
            model: ["StationA", "StationB", "StationC"]
        }

        Button {
            text: "Pay & Generate Ticket"
            onClicked: {
                let fare = backend.calculateFare("StationA", dest.currentText)
                ticket.text = "Ticket Generated\nFare: ₹" + fare
            }
        }

        Text {
            id: ticket
            text: ""
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            text: "Exit Train"
            onClicked: backend.exitTrain()
        }
    }
}
