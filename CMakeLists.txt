cmake_minimum_required(VERSION 3.14)

project(WeatherApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основные Qt модули
find_package(Qt6 REQUIRED COMPONENTS Widgets Network Positioning Charts UiTools Test)

# Основные исходники приложения
set(SOURCES
    main.cpp
    mainwindow.cpp
    weatherapi.cpp
    location.cpp
    forecastchartwindow.cpp
)

set(HEADERS
    mainwindow.h
    weatherapi.h
    location.h
    forecastchartwindow.h
)

set(UIS
    mainwindow.ui
)

qt6_wrap_ui(UI_HEADERS ${UIS})

# Главная сборка приложения
qt_add_executable(WeatherApp
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

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

# --------------------------
# Тесты
# --------------------------

# # Файлы тестов
# set(TEST_SOURCES
#     tests/weatherapitest.cpp
#     tests/emojitest.cpp
#     tests/urltest.cpp
#     tests/weatherapitest.h
#     tests/emojitest.h
#     tests/urltest.h
#     tests/main.cpp
# )

# # Добавляем тесты как отдельное исполняемое
# qt_add_executable(WeatherTests
#     ${TEST_SOURCES}
#     weatherapi.cpp # нужен код из основного приложения
# )

# target_include_directories(WeatherTests PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     ${CMAKE_CURRENT_BINARY_DIR}
# )

# target_link_libraries(WeatherTests PRIVATE
#     Qt6::Test
#     Qt6::Network
#     Qt6::Core
# )

# # Объявляем unit-тесты как ctest
# enable_testing()
# add_test(NAME RunWeatherTests COMMAND WeatherTests)
