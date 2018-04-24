import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 1920
    height: 1080
    color: "#00000000"



    Page {
        id: pageAccueil
        width: 1920
        height: 1080
        title: none.none
        anchors.verticalCenter: parent.verticalCenter
        visible: false



        Text {
            id: olivier
            x: 910
            y: 863
            width: 123
            height: 19
            color: "#000000"
            text: qsTr("Olivier Le Moine")
            font.family: "Tahoma"
            font.pixelSize: 18
        }

        Text {
            id: francois
            x: 910
            y: 890
            width: 132
            height: 21
            text: qsTr("François Morillon")
            font.pixelSize: 18
        }

        Text {
            id: by
            x: 968
            y: 841
            width: 132
            height: 15
            text: qsTr("By")
            font.pixelSize: 18
        }

        Text {
            id: alexis
            x: 910
            y: 917
            width: 123
            height: 26
            text: qsTr("Alexis Grall")
            font.pixelSize: 18
        }

        Text {
            id: pierre
            x: 910
            y: 949
            width: 123
            height: 37
            text: qsTr("Pierre Gelgon")
            font.pixelSize: 18
        }

        Button {
            id: entrer
            x: 868
            y: 756
            width: 194
            height: 60
            text: qsTr("Entrer")
        }

        Image {
            id: simBus
            x: 656
            y: 144
            width: 660
            height: 482
            source: "simbusinterface.png"
        }

    }



    Page {
        id: base
        x: -6
        y: 0
        width: 1926
        height: 1080
        visible: true
        title: entrer.none

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
                y: 104
                width: 446
                height: 344
                color: "#ffffff"
                border.width: 6
                border.color: "#ffff00"

                Text {
                    id: gr
                    x: 58
                    y: 38
                    width: 144
                    height: 34
                    color: "#000000"
                    text: qsTr("Graphe de Répartition :")
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
                y: 8
                width: 446
                height: 95
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









    }


    Connections {
        target: ajouterarret
        onClicked: { window.state = "" }
    }





}
