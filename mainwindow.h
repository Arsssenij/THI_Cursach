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

private slots:
    void onUpdateButtonClicked();
    void onWeatherDataReceived(const QString &data);

private:
    Ui::MainWindow *ui;
    WeatherAPI *weatherAPI;
    Location *location;
    QMap<QString, QPair<double, double>> cityCoordinates; // город -> (широта, долгота)
    void setupCityCoordinates();
};

#endif // MAINWINDOW_H
