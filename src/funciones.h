#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#ifndef FUNCIONES_H
#define FUNCIONES_H

class Funcion {
    private:
        float a, b, c;
        
    public:
        Funcion(float a, float b, float c);
        float A();
        float B();
        float C();

};

class Calculadora {
    private:
        Funcion parabola;
    public:
    Calculadora(float a,float b,float c);

    float CalculoDiscriminante();
    void CalculoVertice(float dis);
    void CorteEjeY();
    void MostrarTabla();
    void GraficarConsola();
};

void PedirCoeficientes(float &a, float &b, float &c);
void ExplicarFuncionCuadratica();

#endif
