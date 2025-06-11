cmake_minimum_required(VERSION 3.14)

project(WeatherApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network Positioning Charts UiTools)

set(SOURCES
    main.cpp
    mainwindow.cpp
    weatherapi.cpp
    location.cpp
)

set(HEADERS
    mainwindow.h
    weatherapi.h
    location.h
)

set(UIS
    mainwindow.ui
)

qt6_wrap_ui(UI_HEADERS ${UIS})

qt_add_executable(WeatherApp
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

# ВАЖНО: подключить moc-файлы
set_target_properties(WeatherApp PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_include_directories(WeatherApp PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(WeatherApp PRIVATE
    Qt6::Widgets
    Qt6::Network
    Qt6::Positioning
    Qt6::Charts
)
