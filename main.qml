import QtQuick 2.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    color: "black"

    Item {
        focus: true
        Keys.onPressed: (event)=> {
                            if(event.key < 54 && event.key > 48) {
                                // var x = event.key
                                // if(x === 53) x += 13
                                // else x += 18
                                // ['', 'C', 'D', '', 'F', 'G', 'A']
                                var x = event.key
                                switch(x) {
                                    case 49 : x = 67; break;
                                    case 50 : x = 68; break;
                                    case 51 : x = 69; break;
                                    case 52 : x = 66; break;
                                    case 53 : x = 65; break;
                                    default: return
                                }

                                Player.blackPressed(x)
                            }
                            else if(event.key < 71 && event.key > 64) {
                                Player.whitePressed(event.key)
                            }
                        }
    }

    Repeater {
        model:['C', 'D', 'E', 'F', 'G', 'A', 'B']
        delegate: Rectangle {
            x: index * width
            width: (root.width / 7)
            height: root.height
            border.color: "black"
            border.width: 1
            color: msArea.pressed ? "gray" : msArea.containsMouse ? "light gray" : "white"

            MouseArea {
                id: msArea
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    var x = modelData;
                    Player.whitePressed(x.charCodeAt(0))
                }
            }
        }
    }

    Repeater {
        model: ['', 'C', 'D', '', 'F', 'G', 'A']
        delegate: Rectangle {
            x: (index * (root.width / 7)) - width / 2
            y: -10
            width: (root.width / 7) * 0.7
            height: root.height * 0.6
            border.color: "black"
            border.width: 1
            color: msArea2.pressed ? "#3d3d3d" : msArea2.containsMouse ? "#212121" : "black"
            visible: (index != 0 && index != 3)
            radius: height * 0.05

            MouseArea {
                id: msArea2
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    var x = modelData;
                    Player.blackPressed(x.charCodeAt(0))
                }
            }
        }
    }
}
