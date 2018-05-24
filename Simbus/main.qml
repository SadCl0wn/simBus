import QtQuick 2.9
import QtQuick.Controls 2.2
import Parametres 1.0
import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6
import QtLocation 5.3
import "parser.js" as Parser
//Parser.parse();
ApplicationWindow {
    id: window
    visible: true
    height:381
    width:330
    Parametres{
        id:param
        adressedepart:""
        adressearrivee:""
        heure: 0
        minute:0

    }

    color: "#00000000"

    Image {
        id: image
        x: 0
        y: 9
        width: 330
        height: 381
        visible: true
        source: "interfacesimbus.png"
    }

    Page {
        id: base
        x: 15
        y: 0
        width: 1876
        height: 1052
        visible: false
        title: "simBus"


        Timer {
            interval: 5000; running: true
            onTriggered: {
                image.visible=false
                window.x=0
                window.y=30
                base.visible=true
                window.width=1920
                window.height=1080
            }


        }

        Rectangle {
            id: simulation
            x: 1517
            y: 300
            width: 391
            height: 745
            color: "#ffffff"
            border.color: "#000000"
            border.width: 4
            visible: true

            Rectangle {
                id: repartition
                x: 0
                y: 395
                width: 391
                height: 357
                color: "#ffffff"
                border.width: 4
                border.color: "#000000"

                Text {
                    id: gr
                    x: 58
                    y: 38
                    width: 187
                    height: 34
                    color: "#000000"
                    text: qsTr("Graphe de Répartitions :")
                    styleColor: "#f81e1e"
                    font.pixelSize: 18
                }
            }

            Text {
                id: resimulation
                x: 35
                y: 104
                width: 220
                height: 42
                text: qsTr("Résultats de la simulation:")
                font.underline: true
                style: Text.Normal
                font.family: "Normal"
                font.pixelSize: 20
            }

            Text {
                id: tempsmoyen
                x: 29
                y: 216
                width: 96
                height: 22
                text: qsTr("Temps moyen de trajet")
                font.pixelSize: 12
            }

            Text {
                id: ecarttype
                x: 35
                y: 297
                width: 96
                height: 43
                text: qsTr("Ecart-type")
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle
            x: 1517
            y: 190
            width: 391
            height: 114
            color: "#ffffff"
            border.width: 4
            border.color: "#000000"

            Button {
                id: simuler
                x: 134
                y: 37
                text: qsTr("Simuler")
                font.pointSize: 14
                onClicked: {
                    param.simuler()
                }
            }
        }

        Rectangle {
            id: parametres
            x: -15
            y: 0
            width: 1923
            height: 194
            color: "#ffffff"
            visible: true
            border.color: "#000000"
            border.width: 4

            Slider {
                id: slider
                x: 1439
                y: 120
                value: 0.5
            }

            Button {
                id: valider
                x: 1340
                y: 41
                width: 128
                height: 40
                onClicked: {
                    param.adressedepart=ad.text
                    param.adressearrivee=aa.text
                    param.heure=heure.value
                    param.minute=minute.value
                    param.save()


                }

                text: qsTr("Valider")
                font.pointSize: 18
                font.family: "Times New Roman"
            }

            TextField {
                id: aa
                text:param.adressearrivee
                x: 231
                y: 113
                font.pointSize: 18
            }

            TextField {
                id: ad
                text:param.adressedepart
                x: 231
                y: 41
                font.pointSize: 18
            }

            Text {
                id: zoom
                x: 1340
                y: 128
                width: 56
                height: 24
                color: "#000000"
                text: qsTr("Zoom")
                font.family: "Tahoma"
                font.pixelSize: 18
            }

            Text {
                id: horaire
                x: 671
                y: 48
                width: 71
                height: 25
                color: "#000000"
                text: qsTr("Horaire")
                font.family: "Tahoma"
                font.pixelSize: 18
            }

            Text {
                id: adressearrivee
                x: 68
                y: 120
                width: 153
                height: 26
                color: "#000000"
                text: qsTr("Adresse d'arrivée")
                font.family: "Tahoma"
                font.pixelSize: 18
            }

            Text {
                id: adressedepart
                x: 68
                y: 48
                width: 153
                height: 25
                color: "#000000"
                text: qsTr("Adresse de départ")
                font.family: "Tahoma"
                font.pixelSize: 18
            }

            Text {
                id: h
                x: 910
                y: 51
                width: 21
                height: 22
                color: "#000000"
                text: qsTr("H")
                font.family: "Tahoma"
                font.pixelSize: 18
            }

            SpinBox {
                id: heure
                from:0
                to:23
                value:0
                editable: true
                x: 735
                y: 41
            }

            SpinBox {
                id: minute
                from:0
                value:0
                editable: true
                to:59
                x: 957
                y: 42
            }

            Button {
                id: ajoutArret
                x: 620
                y: 120
                width: 163
                height: 41
                text: qsTr("ajouter arret")
                font.pointSize: 14
                onClicked: {
                    //param.ajoutArret("55,66");
                    markermodel.setAddAction(true)
                }
            }

            Button {
                id: modifArret
                x: 857
                y: 120
                width: 163
                text: qsTr("modifier arret")
                font.pointSize: 14
                onClicked: {
                    param.modificationArret("55,66","33,88");
                }
            }

            Button {
                id: supprArret
                x: 1064
                y: 120
                width: 177
                height: 40
                text: qsTr("supprimer arret")
                font.pointSize: 14
                onClicked: {
                    param.supprimerArret("55,66");
                }
            }
















        }

        Rectangle {
            id: map
            x: 0
            y: 200
            width: 1511
            height: 852
            color: "#ffffff"

        Plugin {
               id: mapPlugin
               name: "osm"

        }

        Map {
            id:mapview
            anchors.rightMargin: -5
            anchors.bottomMargin: -4
            anchors.topMargin: -6
            anchors.leftMargin: -17
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate( 48.390394,-4.486076) // brest
            zoomLevel: 14
             MapItemView{
                 model:markermodel
                 delegate: mapcomponent
             }

           }
        Component {
                id: mapcomponent
                MapQuickItem {
                    id: marker
                    anchorPoint.x: imagemarker.width/4
                    anchorPoint.y: imagemarker.height
                    coordinate: position

                    sourceItem: Image {
                        id: imagemarker
                        source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
                    }
                }
            }

            MouseArea {
                anchors.fill: parent

                onPressAndHold:  {
                    var coordinate = mapview.toCoordinate(Qt.point(mouse.x,mouse.y))
                    //console.log(coordinate.latitude+ "-" + coordinate.longitude)
                   markermodel.addMarker(coordinate)
                    param.ajoutArret(coordinate.latitude+ ";" + coordinate.longitude)
                }
            }
    }

        }


}
