#include "funciones.h"

int main(){
    int opcion;
    float a, b, c;

    ExplicarFuncionCuadratica();
    PedirCoeficientes(a, b, c);
    Calculadora calculo(a, b, c);

    float dis = (b*b)-(4.0*a*c);

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
            dis = calculo.CalculoDiscriminante();
        } else if (opcion == 2) {
            calculo.CalculoVertice(dis);
        } else if (opcion == 3) {
            calculo.CorteEjeY();
        } else if (opcion == 4) {
            calculo.MostrarTabla();
        } else if (opcion == 5) {
            calculo.GraficarConsola();
        } else if (opcion == 6) {
            std::cout << "Hasta luego!\n";
        } else {
            std::cout << "Opcion no valida\n";
        }
    } while (opcion != 6);

    return 0;
}
