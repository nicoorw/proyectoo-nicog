#include <iostream>
#include <string>
#include "funciones.h"

int main(){
    float a, b, c;
    int opcion;

    // Explica la funcion cuadratica y pide los coeficientes al usuario
    ExplicarFuncionCuadratica();
    PedirCoeficientes(a, b, c);

    // Se calcula el discriminante inicial para usarlo en el vertice
    float dis = (b*b)-(4.0*a*c);

    // Menu principal con todas las funcionalidades disponibles
    do {
        std::cout << "\n---MENU---\n";
        std::cout << "1. Calcular discriminante y raices\n";
        std::cout << "2. Calcular vertice\n";
        std::cout << "3. Ver corte en eje Y\n";
        std::cout << "4. Ver tabla de valores\n";
        std::cout << "5. Ver grafica en consola\n";
        std::cout << "6. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            // Se actualiza el discriminante por si el usuario ingreso nueva funcion
            dis = CalculoDiscriminante(a, b, c);
        } else if (opcion == 2) {
            CalculoVertice(a, b, dis);
        } else if (opcion == 3) {
            CorteEjeY(c);
        } else if (opcion == 4) {
            MostrarTabla(a, b, c);
        } else if (opcion == 5) {
            GraficarConsola(a, b, c);
        } else if (opcion == 6) {
            std::cout << "Hasta luego!\n";
        } else {
            std::cout << "Opcion no valida\n";
        }
    } while (opcion != 6);

    return 0;
}
