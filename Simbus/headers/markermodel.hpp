#ifndef MARKERMODEL_H
#define MARKERMODEL_H

#include <QAbstractListModel>
#include <QGeoCoordinate>

class MarkerModel : public QAbstractListModel
{
    Q_OBJECT

public:
    using QAbstractListModel::QAbstractListModel;
    enum MarkerRoles{positionRole = Qt::UserRole + 1};
    MarkerModel(){allowMarker=false;}   //on ne peut pas ajouter d'arret au debut

    Q_INVOKABLE void addMarker(const QGeoCoordinate &coordinate){ //
        if (allowMarker){   // si allowMarker est true on peut ajouter des arrets


        beginInsertRows(QModelIndex(), rowCount(), rowCount()); // prevenir liste qu elle va etre modifiée
        m_coordinates.append(coordinate);   // ajout coordonnées arrets dans la liste m_coordonnates
        endInsertRows(); // dire que l action est finie et sert à actualiser la carte
        }
        setAddAction(false); // quand c est fini on peut ne plus ajouter de marker car allow marker passe à false
    }


    int rowCount(const QModelIndex &parent = QModelIndex()) const override{ // retourner nombre element de la liste
        Q_UNUSED(parent)
        return m_coordinates.count();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{  //retourner element liste
        if (index.row() < 0 || index.row() >= m_coordinates.count()) // verifie si la liste n est pas vide
            return QVariant();
        if(role== MarkerModel::positionRole)
            return QVariant::fromValue(m_coordinates[index.row()]);
        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const{
        QHash<int, QByteArray> roles;
        roles[positionRole] = "position";
        return roles;
    }
    Q_INVOKABLE void setAddAction(bool val){ //autoriser ou non l ajout d un marker
        allowMarker=val;


    }
    Q_INVOKABLE void removeMarker(const QGeoCoordinate &coordinate) { // supprimer arret liste
            int position = m_coordinates.indexOf(coordinate);
            if (allowMarker && position > -1) {
                beginRemoveRows(QModelIndex(), position, 1);
                m_coordinates.removeOne(coordinate);
                endRemoveRows();
            }
            setAddAction(false);
        }
    Q_INVOKABLE void removeAllMarkers() // supprimer tous les elements de la liste
       {
           beginResetModel();
           m_coordinates.clear();
           endResetModel();
       }

private:
    QList<QGeoCoordinate> m_coordinates;  // liste de coordonnées
    bool allowMarker; // sert à autoriser ou non l ajout d'un arret

};

#endif // MARKERMODEL_H
