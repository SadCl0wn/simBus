import QtQuick 2.9
import QtQuick.Window 2.2
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Controls 2.3
//import Local 1.0 //liaison qml/ cpp
Window {
    width: 512
    height: 512
    visible: true

   /*qmlcpp{
       id:qmlObject
       run: false
    }*/


    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...

            PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
            PluginParameter { name: "osm.mapping.host"; value: "http://osm.tile.server.address/" }
            PluginParameter { name: "osm.mapping.copyright"; value: "All mine" }
            PluginParameter { name: "osm.routing.host"; value: "http://osrm.server.address/viaroute" }
            PluginParameter { name: "osm.geocoding.host"; value: "http://geocoding.server.address" } }


    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(48.743658, -3.53490) // Brest
        zoomLevel: 14
    }
    TextField{
        id:adresse
        height: 50
        width: 100
        onEditingFinished: {
            console.log(text)
            geocodeModel.query = text

            geocodeModel.update()

        }

    }


    Plugin {
        id: aPlugin
    }
    GeocodeModel {
        id: geocodeModel
        plugin: aPlugin
        autoUpdate: false
    }

    /*geocodeModel.query = "3 rue rené cassin,Bretagne, France"
    geocodeModel.update()}*/
    RouteModel {
        id: routeModel
        //plugin : map.plugin
        query:  RouteQuery {
            id: routeQuery
        }
        onStatusChanged: {
            if (status == RouteModel.Ready) {
                switch (count) {
                case 0:
                    // technically not an error
                    map.routeError()
                    break
                case 1:
                    map.showRouteList()
                    break
                }
            } else if (status == RouteModel.Error) {
                map.routeError()
            }
        }
    }
    MapItemView {
        model: routeModel
        delegate: routeDelegate
    }
    Component {
        id: routeDelegate

        MapRoute {
            id: route
            route: routeData
            line.color: "#46a2da"
            line.width: 5
            smooth: true
            opacity: 0.8
        }
    }
    PositionSource{
        active: true
    }


}
