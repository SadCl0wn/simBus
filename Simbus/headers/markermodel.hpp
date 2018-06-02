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
    MarkerModel(){allowMarker=false;}

    Q_INVOKABLE void addMarker(const QGeoCoordinate &coordinate){
        if (allowMarker){


        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_coordinates.append(coordinate);
        endInsertRows();
        }
        setAddAction(false);
    }


    int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        Q_UNUSED(parent)
        return m_coordinates.count();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{
        if (index.row() < 0 || index.row() >= m_coordinates.count())
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
    Q_INVOKABLE void setAddAction(bool val){
        allowMarker=val;


    }
    Q_INVOKABLE void removeMarker(const QGeoCoordinate &coordinate) {
            int position = m_coordinates.indexOf(coordinate);
            if (allowMarker && position > -1) {
                beginInsertRows(QModelIndex(), position, 1);
                m_coordinates.removeOne(coordinate);
                endRemoveRows();
            }
            setAddAction(false);
        }


private:
    QList<QGeoCoordinate> m_coordinates;
    bool allowMarker;

};

#endif // MARKERMODEL_H
