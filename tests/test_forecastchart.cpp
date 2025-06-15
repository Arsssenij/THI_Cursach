#include <QtTest>
#include "forecastchartwindow.h"

class ForecastChartTest : public QObject {
    Q_OBJECT
private slots:
    void testChartSetup();
};

void ForecastChartTest::testChartSetup() {
    ForecastChartWindow window;

    QList<QPair<QString, double>> data = {
        {"2025-06-13 12:00", 20.0},
        {"2025-06-13 15:00", 22.5},
        {"2025-06-13 18:00", 19.0}
    };
    QList<QString> icons = {"☀️", "⛅", "🌧"};

    window.setForecastData(data, icons);  // Добавляем данные и оси

    auto chart = window.findChild<QChartView *>();
    QVERIFY(chart != nullptr);

    QCOMPARE(chart->chart()->axes().size(), 2); // Ожидаем 2 оси
}

QTEST_MAIN(ForecastChartTest)
#include "test_forecastchart.moc"

