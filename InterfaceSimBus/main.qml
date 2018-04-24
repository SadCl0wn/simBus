import QtQuick 2.9
import QtQuick.Controls 2.2
import Parametres 1.0
ApplicationWindow {
    id: window
    visible: true
    height:381
    width:330
    Parametres{
        id:param
        adressedepart:""

    }

    color: "#00000000"
    Image {
        id: image
        x: 0
        y: 0
        width: 330
        height: 381
        visible: true
        source: "interfacesimbus.png"
    }
Page {
    id: base
    x: -6
    y: 0
    width: 1885
    height: 1045
    visible: false
    title: "simBus"


    Timer {
                interval: 5000; running: true
                onTriggered: {
                    image.visible=false
                    window.x=30
                    window.y=30
                    base.visible=true
                    window.width=1920
                    window.height=1080
                }


                }

    Rectangle {
        id: simulation
        x: 1053
        y: 627
        width: 867
        height: 453
        color: "#ffffff"
        border.color: "#ffff00"
        border.width: 6
        visible: true

        Rectangle {
            id: repartition
            x: 421
            y: 97
            width: 446
            height: 351
            color: "#ffffff"
            border.width: 6
            border.color: "#ffff00"

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
            text: qsTr("Temps moyen de traget")
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

        Rectangle {
            id: simuler
            x: 421
            y: 0
            width: 446
            height: 103
            color: "#ffffff"
            border.color: "#ffff00"
            border.width: 6

            Button {
                id: simulerbouton
                x: 173
                y: 27
                text: qsTr("Simuler")
                font.pointSize: 18
                autoExclusive: true
            }
        }
    }

    Rectangle {
        id: parametres
        x: 0
        y: 0
        width: 1920
        height: 194
        color: "#ffffff"
        border.color: "#ffff00"
        border.width: 6

        Slider {
            id: slider
            x: 825
            y: 125
            value: 0.5
        }

        Button {
            id: valider
            x: 1741
            y: 77
            width: 128
            height: 40
            onClicked: {
               param.adressedepart=ad.text
               param.save()
            }

            text: qsTr("Valider")
            font.pointSize: 18
            font.family: "Times New Roman"
        }

        TextField {
            id: heure
            x: 1337
            y: 41
            width: 69
            height: 41
        }

        TextField {
            id: aa
            x: 860
            y: 41
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
            x: 763
            y: 133
            width: 56
            height: 24
            color: "#000000"
            text: qsTr("Zoom")
            font.family: "Tahoma"
            font.pixelSize: 18
        }

        Text {
            id: horaire
            x: 1260
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
            x: 701
            y: 49
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
            x: 1425
            y: 53
            width: 1
            height: 22
            color: "#000000"
            text: qsTr("H")
            font.family: "Tahoma"
            font.pixelSize: 18
        }
















    }

    Rectangle {
        id: actionsarret
        x: 1655
        y: 190
        width: 265
        height: 440
        color: "#ffffff"
        border.width: 8
        border.color: "#ffff00"

        Button {
            id: ajouterarret
            x: 83
            y: 84
            width: 151
            height: 40
            text: qsTr("Ajouter arrêt")
            font.pointSize: 14
        }

        Button {
            id: modifierarret
            x: 83
            y: 200
            width: 151
            height: 40
            text: qsTr("Modifier arrêt")
            font.pointSize: 14
        }

        Button {
            id: supprimerarret
            x: 83
            y: 310
            text: qsTr("Supprimer Arrêt")
            font.pointSize: 14
        }
    }









}}








