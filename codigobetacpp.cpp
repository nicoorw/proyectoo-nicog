#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
    float a, b, c, discriminante;
    cout << "La funcion cuadratica esta compuesta de forma tal que ax² + bx + c .\n" << endl;
    cout << "Ingresa el valor de a (recuerda que es el valor que acompaña al x²)" << endl;
    cin >> a;
    if ( a == 0){
        cout << "La funcion no es cuadratica" << endl;
        return 0;
    }
    cout << "Ingresa el valor de b (recuerda que es el valor que acompaña al x)" << endl;
    cin >> b;
    cout << "Ingresa el valor de c (recuerda que es el termino independiente)" << endl;
    cin >> c;
    if (a > 0){
        cout << "La parabola abre hacia arriba (convexa), por lo que tiene un minimo\n" << endl;
    }
    else {
        cout << "La parabola abre hacia abajo (concava), por lo que tiene un maximo\n";
    }
    if ( b > 0 and c > 0){
        cout << "La funcion a trabajar seria " << a << "x² +" << b << "x +" << c << endl;
    }
    else if ( b > 0 ){
        cout << "La funcion a trabajar seria " << a << "x² +" << b << "x " << c << endl;
    }
    else if ( c > 0 ){
        cout << "La funcion a trabajar seria " << a << "x² " << b << "x +" << c << endl;
    }
    discriminante = (b*b)-(4*a*c);
    cout << "\n EL RESULTADO DEL DISCRIMINANTE ES\n" << endl;
    cout << "El discriminante(Δ) es :" << discriminante << endl;
    return 0;
}
