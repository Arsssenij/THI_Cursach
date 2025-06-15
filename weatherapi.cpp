#include "weatherapi.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QUrlQuery>
#include <QDateTime>

WeatherAPI::WeatherAPI(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished, this, &WeatherAPI::onWeatherReply);
}

void WeatherAPI::fetchThreeHourForecast(double lat, double lon)
{
    QUrl url("https://api.openweathermap.org/data/2.5/forecast");
    QUrlQuery query;
    query.addQueryItem("lat", QString::number(lat));
    query.addQueryItem("lon", QString::number(lon));
    query.addQueryItem("units", "metric");
    query.addQueryItem("lang", "ru");
    query.addQueryItem("appid", apiKey);
    url.setQuery(query);

    QNetworkRequest request(url);
    manager.get(request);
}

QString WeatherAPI::weatherEmoji(const QString &description)
{
    QString desc = description.toLower();
    if (desc.contains("дожд")) return "🌧️";
    if (desc.contains("гроза")) return "⛈️";
    if (desc.contains("снег")) return "❄️";
    if (desc.contains("пасмурно")) return "☁️";
    if (desc.contains("облачно")) return "🌥️";
    if (desc.contains("ясно")) return "☀️";
    if (desc.contains("туман")) return "🌫️";
    return "🌡️"; // по умолчанию
}

void WeatherAPI::onWeatherReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        emit weatherDataReceived("Ошибка: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray response = reply->readAll();
    QString result = parseThreeHourForecast(response);  // используем новый парсер

    emit weatherDataReceived(result);
    reply->deleteLater();
}


QString WeatherAPI::parseThreeHourForecast(const QByteArray &response)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
    if (!jsonDoc.isObject()) return "Ошибка парсинга прогноза";

    QJsonObject root = jsonDoc.object();
    QJsonArray list = root["list"].toArray();

    QString result;
    QDate currentDate = QDate::currentDate();

    static const QStringList daysOfWeek = {
        "вс", "пн", "вт", "ср", "чт", "пт", "сб"
    };

    for (int i = 0; i < list.size(); i += 2) {  // шаг 6 часов
        QJsonObject forecast = list[i].toObject();

        qint64 dt = forecast["dt"].toInt();
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(dt);

        QJsonObject main = forecast["main"].toObject();
        double temp = main["temp"].toDouble();
        double feelsLike = main["feels_like"].toDouble();

        QJsonObject wind = forecast["wind"].toObject();
        double windSpeed = wind["speed"].toDouble();

        QString description;
        QJsonArray weatherArr = forecast["weather"].toArray();
        if (!weatherArr.isEmpty()) {
            description = weatherArr[0].toObject()["description"].toString();
        }

        QString dayLabel;
        QDate forecastDate = dateTime.date();
        int daysDiff = currentDate.daysTo(forecastDate);
        int dayOfWeekIndex = forecastDate.dayOfWeek() % 7;
        dayOfWeekIndex = (dayOfWeekIndex == 7) ? 0 : dayOfWeekIndex;

        QString russianDay = daysOfWeek[dayOfWeekIndex];

        if (daysDiff == 0) {
            dayLabel = QString("Сегодня (%1)").arg(russianDay);
        } else if (daysDiff == 1) {
            dayLabel = QString("Завтра (%1)").arg(russianDay);
        } else {
            dayLabel = QString("%1-%2 (%3)")
            .arg(forecastDate.day(), 2, 10, QChar('0'))
                .arg(forecastDate.month(), 2, 10, QChar('0'))
                .arg(russianDay);
        }

        result += QString("%1 %2: %3°C (ощущается как %4°C), %5 %6\nВетер: %7 м/с\n\n")
                      .arg(dayLabel)
                      .arg(dateTime.toString("HH:mm:ss"))
                      .arg(temp, 0, 'f', 1)
                      .arg(feelsLike, 0, 'f', 1)
                      .arg(description)
                      .arg(weatherEmoji(description))
                      .arg(windSpeed, 0, 'f', 1);
    }

    return result.trimmed();
}
QUrl WeatherAPI::buildForecastUrl(double lat, double lon)
{
    QUrl url("https://api.openweathermap.org/data/2.5/forecast");
    QUrlQuery query;
    query.addQueryItem("lat", QString::number(lat));
    query.addQueryItem("lon", QString::number(lon));
    query.addQueryItem("units", "metric");
    query.addQueryItem("lang", "ru");
    query.addQueryItem("appid", apiKey);
    url.setQuery(query);
    return url;
}

