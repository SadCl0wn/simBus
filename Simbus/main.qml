import QtQuick 2.9
import QtQuick.Controls 2.2
import Parametres 1.0
import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6
import QtLocation 5.3
import InterfaceQml 1.0
import "parser.js" as Parser


ApplicationWindow {
    id: window
    visible: true
    height:416
    width:330

    Parametres{
        id:param
        latitudeBD:""
        longitudeBD:""
        latitudeHG:""
        longitudeHG:""
        heure: 0
        minute:0

    }
    InterfaceQml{
        id: interfaceQml
    }
    property string stateAction: ""



    color: "#00000000"

    Image {
        id: image
        x: 0
        y: 0
        width: 330
        height: 416
        visible: true
        source: "interfacesimbus.png"
    }

    Page {
        id: base
        x: 0
        y: 0
        width: 1436
        height: 850
        visible:false
        title: "simBus"

        Timer {
            interval: 5000; running: true
            onTriggered: {
                image.visible=false
                window.x=200
                window.y=100
                base.visible=true
                window.width=1436
                window.height=850
            }
        }

        Rectangle {
            id: simulation
            x: 1045
            y: 319
            width: 429
            height: 531
            color: "#ffffff"
            border.color: "#000000"
            border.width: 4
            visible: true

            Rectangle {
                id: repartition
                x: 0
                y: 319
                width: 429
                height: 212
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
                x: 29
                y: 34
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
                y: 112
                width: 96
                height: 22
                text: qsTr("Temps moyen de trajet")
                font.pixelSize: 12
            }

            Text {
                id: ecarttype
                x: 29
                y: 214
                width: 96
                height: 22
                text: qsTr("Ecart-type")
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle
            x: 1045
            y: 192
            width: 429
            height: 132
            color: "#ffffff"
            border.width: 4
            border.color: "#000000"

            Button {
                id: simuler
                x: 165
                y: 46
                text: qsTr("Simuler")
                font.pointSize: 14
                onClicked: {
                    param.simuler()
                }
            }
        }

        Rectangle {
            id: parametres
            x: 0
            y: 0
            width: 1474
            height: 194
            color: "#ffffff"
            visible: true
            border.color: "#000000"
            border.width: 4

            Button {
                id: valider
                x: 1261
                y: 43
                width: 128
                height: 40
                onClicked: {
                    param.longitudeHG=longitudehg.text   // //appel set de longitudeHG pour que ça prenne la longitudehg souhaitéee
                    param.latitudeHG=latitudehg.text
                    param.longitudeBD=longitudebd.text
                    param.latitudeBD=latitudebd.text
                    param.heure=heure.value
                    param.minute=minute.value
                    param.save()
                }

                text: qsTr("Valider")
                font.pointSize: 18
                font.family: "Times New Roman"
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
                id: coordonneesHG
                x: 170
                y: 18
                width: 303
                height: 25
                color: "#000000"
                text: qsTr("Coordonnées Point en Haut à Gauche")
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

                    markermodel.setAddAction(true) // autorise action sur marker
                    stateAction = "AJOUT" //indication etat bouton par appui sur un des deux boutons

                }
            }

            Button {
                id: valzone
                x: 857
                y: 120
                width: 163
                text: qsTr("VALIDER ZONE ")
                font.pointSize: 14

                onClicked: {
                    Parser.parse(longitudehg.text,latitudehg.text,longitudebd.text,latitudebd.text)  //envoi les données au parser
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

                        stateAction = "SUPPR" //appui sur suppr arret, changement etat variable state action
                }
            }

            Text {
                id: coordonneesBD
                x: 170
                y: 101
                width: 303
                height: 25
                color: "#000000"
                text: qsTr("Coordonnées Point en Bas à Droite")
                font.family: "Tahoma"
                font.pixelSize: 18
            }

            Text {
                id: longitudehg
                x: 442
                y: 58
                width: 134
                height: 24
                text:""
                font.capitalization: Font.SmallCaps
                font.pixelSize: 12
            }

            Text {
                id: latitudehg
                x: 170
                y: 57
                width: 127
                height: 26
                text: ""
                font.pixelSize: 12
            }

            Text {
                id: latitudebd
                x: 170
                y: 138
                width: 127
                height: 26
                font.pixelSize: 12
            }

            Text {
                id: longitudebd
                x: 442
                y: 137
                width: 134
                height: 26
                text: ""
                font.pixelSize: 12
            }

            Text {
                id: text1
                x: 82
                y: 138
                width: 77
                height: 23
                text: qsTr("Latitude:")
                font.pixelSize: 16
            }

            Text {
                id: text2
                x: 359
                y: 138
                width: 77
                height: 23
                text: qsTr("Longitude:")
                font.pixelSize: 16
            }

            Text {
                id: text3
                x: 359
                y: 59
                width: 77
                height: 23
                text: qsTr("Longitude:")
                font.pixelSize: 16
            }

            Text {
                id: text4
                x: 82
                y: 59
                width: 77
                height: 23
                text: qsTr("Latitude:")
                font.pixelSize: 16
            }
        }

        Rectangle {
            id: map
            x: 0
            y: 200
            width: 1039
            height: 641
            color: "#ffffff"

            Plugin {
                id: mapPlugin
                name: "osm"
            }

            Map {
                id:mapview //charger carte avec map plugin(utilisation openstreet map)
                anchors.rightMargin: -5
                anchors.bottomMargin: 0
                anchors.topMargin: -6
                anchors.leftMargin: 0
                anchors.fill: parent
                plugin: mapPlugin
                center: QtPositioning.coordinate( 48.390394,-4.486076) // brest
                zoomLevel: 14
                MapItemView{   // pour chaque element de liste markermodel on créée un map item view qui va afficher chaque element via mapcomponenent
                    model:markermodel
                    delegate: mapcomponent
                }

            }

            Component {  // dectection chose à afficher
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



            MouseArea { //gerer evenement de la souris
                anchors.leftMargin: 8
                anchors.bottomMargin: 8
                anchors.fill: parent

                onPressAndHold:  {
                                    var coordinate = mapview.toCoordinate(Qt.point(mouse.x,mouse.y))  // creation variable qui contient les coordonnees de la où on a clické

                                    if(stateAction === "AJOUT") {
                                        markermodel.addMarker(coordinate) // ajout marker dans la liste avec ses coordonnees
                                        param.ajoutArret(coordinate.latitude+ ";" + coordinate.longitude)   //ajout coordonnées dans fichier texte
                                        interfaceQml.addArret(coordinate.latitude, coordinate.longitude) //ajout pour afficher arret
                                    } else if(stateAction === "SUPPR") {
                                        markermodel.removeMarker(coordinate) // supprimer un arret
                                        param.supprimerArret(coordinate.latitude+ ";" + coordinate.longitude)  //supprimer coordonnées dans fichier texte
                                    }
                                }

                onWheel: { var coordinateTopLeft = mapview.toCoordinate(Qt.point(map.x, map.y))  //sur scroll souris : on créé 2 variables qui vont recupérer le coordonnées de la map item view
                    var coordinateBottomRight = mapview.toCoordinate(Qt.point(mapview.x+mapview.width, mapview.y+mapview.height))
                    longitudehg.text=coordinateTopLeft.longitude  // on ecrit dans l interface les informations récupérer avec les coordinate...
                    latitudehg.text=coordinateTopLeft.latitude
                    longitudebd.text=coordinateBottomRight.longitude
                    latitudebd.text=coordinateBottomRight.latitude
                    wheel.accepted=false // voir  zoom carte
                }
            }
        }
    }
}
