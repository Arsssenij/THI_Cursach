cmake_minimum_required(VERSION 3.14)

find_package(Qt6 REQUIRED COMPONENTS Test Widgets Charts Network Positioning)

# Пути к исходникам основного приложения
set(APP_SOURCES
    ../mainwindow.cpp
    ../weatherapi.cpp
    ../location.cpp
    ../forecastchartwindow.cpp
)

# UI
set(APP_UIS
    ../mainwindow.ui
)

qt6_wrap_ui(APP_UI_HEADERS ${APP_UIS})

# Общие заголовки
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Включаем автоматическую генерацию moc/uic/rcc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# -----------------------------
# TestWeatherAPI
# -----------------------------
qt_add_executable(TestWeatherAPI
    test_weatherapi.cpp
    ${APP_SOURCES}
    ${APP_UI_HEADERS}
)

target_link_libraries(TestWeatherAPI PRIVATE
    Qt6::Test Qt6::Widgets Qt6::Charts Qt6::Network Qt6::Positioning
)

add_test(NAME TestWeatherAPI COMMAND TestWeatherAPI)

# -----------------------------
# TestMainWindow
# -----------------------------
qt_add_executable(TestMainWindow
    test_mainwindow.cpp
    ${APP_SOURCES}
    ${APP_UI_HEADERS}
)

target_link_libraries(TestMainWindow PRIVATE
    Qt6::Test Qt6::Widgets Qt6::Charts Qt6::Network Qt6::Positioning
)

add_test(NAME TestMainWindow COMMAND TestMainWindow)

# -----------------------------
# TestForecastChart
# -----------------------------
qt_add_executable(TestForecastChart
    test_forecastchart.cpp
    ${APP_SOURCES}
    ${APP_UI_HEADERS}
)

target_link_libraries(TestForecastChart PRIVATE
    Qt6::Test Qt6::Widgets Qt6::Charts Qt6::Network Qt6::Positioning
)

add_test(NAME TestForecastChart COMMAND TestForecastChart)
