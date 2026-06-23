#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <cmath>
#include <utility>
#include <string>


class Funcion {
private:
    float a, b, c;

public:
    Funcion(float a, float b, float c);
    float A() const;
    float B() const;
    float C() const;

};

struct ResultadoDiscriminante{
    float discriminante;
    int cantidadRaices;
    float x1;
    float x2;
    std::string mensaje;
};
struct ResultadoVertice{
    float vx;
    float vy;
};
class Calculadora{
private:
    Funcion parabola;

public:
    Calculadora(float a, float b, float c);
    ResultadoDiscriminante CalculoDiscriminante();
    ResultadoVertice CalculoVertice();
    float CorteEjeY();
    std::vector<std::pair<float, float>> ObtenerTabla();
    float EvaluarFuncion(float x);
};
#endif
