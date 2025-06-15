<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "weatherapi.h"
#include "location.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QPair<QString, double>> forecastPoints;
    QList<QString> weatherIcons;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onUpdateButtonClicked();
    void onWeatherDataReceived(const QString &data);
    void saveForecastToFile();
    void on_graphButton_clicked();

private:
    Ui::MainWindow *ui;
    WeatherAPI *weatherAPI;
    Location *location;
    QMap<QString, QPair<double, double>> cityCoordinates; // город -> (широта, долгота)
    void setupCityCoordinates();
};

#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "weatherapi.h"
#include "location.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QPair<QString, double>> forecastPoints;
    QList<QString> weatherIcons;

private slots:
    void onUpdateButtonClicked();
    void onWeatherDataReceived(const QString &data);
    void saveForecastToFile();
    void on_graphButton_clicked();

private:
    Ui::MainWindow *ui;
    WeatherAPI *weatherAPI;
    Location *location;
    QMap<QString, QPair<double, double>> cityCoordinates; // город -> (широта, долгота)
    void setupCityCoordinates();
};

#endif // MAINWINDOW_H
>>>>>>> 4e7010b0031482420c027338dff6fef4a42a4113
