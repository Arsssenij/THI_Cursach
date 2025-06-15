<<<<<<< HEAD
#ifndef FORECASTCHARTWINDOW_H
#define FORECASTCHARTWINDOW_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class ForecastChartWindow; }
QT_END_NAMESPACE



class ForecastChartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ForecastChartWindow(QWidget *parent = nullptr);
    void setForecastData(const QList<QPair<QString, double>> &data, const QList<QString> &icons);
    ~ForecastChartWindow();

private:
    QChartView *chartView;
    QChart *chart;
    QLineSeries *series;
};

#endif // FORECASTCHARTWINDOW_H
=======
#ifndef FORECASTCHARTWINDOW_H
#define FORECASTCHARTWINDOW_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class ForecastChartWindow; }
QT_END_NAMESPACE



class ForecastChartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ForecastChartWindow(QWidget *parent = nullptr);
    void setForecastData(const QList<QPair<QString, double>> &data, const QList<QString> &icons);
    ~ForecastChartWindow();

private:
    QChartView *chartView;
    QChart *chart;
    QLineSeries *series;
};

#endif // FORECASTCHARTWINDOW_H
>>>>>>> 4e7010b0031482420c027338dff6fef4a42a4113
