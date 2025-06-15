<<<<<<< HEAD
#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>

class Location : public QObject {
    Q_OBJECT
public:
    explicit Location(QObject *parent = nullptr);
    void requestLocation();

signals:
    void locationUpdated(double latitude, double longitude);
    void locationError(const QString &message);

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    void positionError(QGeoPositionInfoSource::Error error);

private:
    QGeoPositionInfoSource *source;
};

#endif // LOCATION_H
=======
#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>

class Location : public QObject {
    Q_OBJECT
public:
    explicit Location(QObject *parent = nullptr);
    void requestLocation();

signals:
    void locationUpdated(double latitude, double longitude);
    void locationError(const QString &message);

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    void positionError(QGeoPositionInfoSource::Error error);

private:
    QGeoPositionInfoSource *source;
};

#endif // LOCATION_H
>>>>>>> 4e7010b0031482420c027338dff6fef4a42a4113
