#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    weatherAPI(new WeatherAPI(this))
{
    ui->setupUi(this);

    setupCityCoordinates();

    // При выборе города сразу загружается прогноз погоды (3-часовой)
    connect(ui->cityComboBox, &QComboBox::currentTextChanged, this, [this](const QString &city) {
        if (cityCoordinates.contains(city)) {
            auto [lat, lon] = cityCoordinates[city];
            weatherAPI->fetchThreeHourForecast(lat, lon);  // Используем 3-часовой прогноз
        }
    });

    connect(weatherAPI, &WeatherAPI::weatherDataReceived, this, &MainWindow::onWeatherDataReceived);

    // По умолчанию выбираем Томск и загружаем его прогноз
    ui->cityComboBox->setCurrentText("Томск");

    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupCityCoordinates()
{
    cityCoordinates["Москва"] = {55.7558, 37.6173};
    cityCoordinates["Санкт-Петербург"] = {59.9343, 30.3351};
    cityCoordinates["Новосибирск"] = {55.0084, 82.9357};
    cityCoordinates["Екатеринбург"] = {56.8389, 60.6057};
    cityCoordinates["Казань"] = {55.7963, 49.1088};
    cityCoordinates["Нижний Новгород"] = {56.2965, 43.9361};
    cityCoordinates["Челябинск"] = {55.1644, 61.4368};
    cityCoordinates["Самара"] = {53.1959, 50.1008};
    cityCoordinates["Уфа"] = {54.7388, 55.9721};
    cityCoordinates["Ростов-на-Дону"] = {47.2357, 39.7015};
    cityCoordinates["Красноярск"] = {56.0153, 92.8932};
    cityCoordinates["Пермь"] = {58.0105, 56.2502};
    cityCoordinates["Воронеж"] = {51.6755, 39.2089};
    cityCoordinates["Волгоград"] = {48.7080, 44.5133};
    cityCoordinates["Томск"] = {56.4847, 84.9481};

    for (const QString &city : cityCoordinates.keys()) {
        ui->cityComboBox->addItem(city);
    }
}

void MainWindow::onUpdateButtonClicked()
{
    QString selectedCity = ui->cityComboBox->currentText();
    if (cityCoordinates.contains(selectedCity)) {
        auto [lat, lon] = cityCoordinates[selectedCity];
        weatherAPI->fetchThreeHourForecast(lat, lon);  // Обновляем 3-часовой прогноз
    }

    ui->statusLabel->setText("Прогноз обновлен");
    ui->statusLabel->setStyleSheet("color: green; font-weight: bold;");
    ui->statusLabel->setVisible(true);

    QTimer::singleShot(3000, this, [this]() {
        ui->statusLabel->setVisible(false);
    });
}

void MainWindow::onWeatherDataReceived(const QString &data)
{
    ui->weatherLabel->setText(data);
}
