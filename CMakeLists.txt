cmake_minimum_required(VERSION 3.16)

project(CalculadoraCuadratica VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(CalculadoraCuadratica
    src/main.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/graficawidget.h
    src/graficawidget.cpp
    src/funciones.h
    src/funciones.cpp
)

target_link_libraries(CalculadoraCuadratica PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
