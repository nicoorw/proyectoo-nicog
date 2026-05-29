#ifndef FUNCIONES_H
#define FUNCIONES_H

// Explica al usuario en que consiste una funcion cuadratica
void ExplicarFuncionCuadratica();

// Pide al usuario los coeficientes a, b, c y valida que a sea distinto de 0
void PedirCoeficientes(float &a, float &b, float &c);

// Calcula el discriminante y las raices de la funcion, retorna el discriminante
float CalculoDiscriminante(float a, float b, float c);

// Calcula y muestra el vertice de la parabola
void CalculoVertice(float a, float b, float dis);

// Muestra el corte de la funcion con el eje Y
void CorteEjeY(float c);

// Muestra una tabla de valores de f(x) para x entre -5 y 5
void MostrarTabla(float a, float b, float c);

// Genera una grafica aproximada de la funcion en consola usando asteriscos
void GraficarConsola(float a, float b, float c);

#endif
