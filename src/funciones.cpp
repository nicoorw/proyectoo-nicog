#include "funciones.h"

Funcion::Funcion(float a, float b, float c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
float Funcion::A() const{
    return a;
}
float Funcion::B() const{
    return b;
}
float Funcion::C() const{
    return c;
}
Calculadora::Calculadora(float a, float b, float c): parabola(a,b,c){
}

//CALCULA EL DISCRIMINANTE Y DETERMINA LAS RAICES
ResultadoDiscriminante Calculadora::CalculoDiscriminante(){
    float a = parabola.A();
    float b= parabola.B();
    float c= parabola.C();

    ResultadoDiscriminante res;
    res.discriminante = (b * b) - (4.0f * a * c);
    res.x1 = 0.0f;
    res.x2 = 0.0f;

    if (res.discriminante > 0) {
        res.cantidadRaices = 2;
        res.x1 = (-b + std::sqrt(res.discriminante)) / (2.0f * a);
        res.x2 = (-b - std::sqrt(res.discriminante)) / (2.0f * a);
        res.mensaje = "Discriminante > 0: existen 2 raices reales.";
    } else if (res.discriminante == 0) {
        res.cantidadRaices = 1;
        res.x1 = (-b) / (2.0f * a);
        res.mensaje = "Discriminante = 0: existe 1 raiz real.";
    } else {
        res.cantidadRaices = 0;
        res.mensaje = "Discriminante < 0: no existen raices reales.";
    }

    return res;
}
//CALCULA EL VERTICE
ResultadoVertice Calculadora::CalculoVertice() {
    float a = parabola.A();
    float b = parabola.B();
    float discriminante = (b * b) - (4.0f * a * parabola.C());

    ResultadoVertice res;
    res.vx = -b / (2.0f * a);
    res.vy = -discriminante / (4.0f * a);
    return res;
}
//RETORNA C
float Calculadora::CorteEjeY() {
    return parabola.C();
}
//GENERA TABLA DE VALORES ENTRE -5 Y 5
std::vector<std::pair<float, float>> Calculadora::ObtenerTabla() {
    std::vector<std::pair<float, float>> tabla;
    float a = parabola.A();
    float b = parabola.B();
    float c = parabola.C();

    for (int x = -5; x <= 5; x++) {
        float fx = a * (x * x) + b * x + c;
        tabla.push_back({(float)x, fx});
    }
    return tabla;
}

float Calculadora::EvaluarFuncion(float x) {
    float a = parabola.A();
    float b = parabola.B();
    float c = parabola.C();
    return a * (x * x) + b * x + c;
}
