#include <QtTest>
#include "weatherapi.h"

class WeatherApiTest : public QObject {
    Q_OBJECT
private slots:
    void testBuildUrl();
};

void WeatherApiTest::testBuildUrl() {
    WeatherAPI api;
    QUrl url = api.buildForecastUrl(55.75, 37.62);
    QVERIFY(url.toString().contains("lat=55.75"));
    QVERIFY(url.toString().contains("lon=37.62"));
    QVERIFY(url.toString().contains("api.openweathermap.org"));
}

QTEST_MAIN(WeatherApiTest)

#include "test_weatherapi.moc"
