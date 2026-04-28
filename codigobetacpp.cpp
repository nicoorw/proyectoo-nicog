#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    float a, b, c, discriminante, x1, x2, x3, vrtx, vrty;
    string consultafun;
    do {
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
        cout << "¿La funcion es correcta?" << endl;
        cin >> consultafun;
    }
        while (consultafun != "si" && consultafun != "Si" && consultafun != "SI" && consultafun != "sii" && consultafun != "SII" && consultafun != "sip");{
            cout << "Perfecto, entonces seguimos con los calculos" << endl;    
        }
    

    discriminante = (b*b)-(4.0*a*c);
    cout << "\n -RESULTADO DEL DISCRIMINANTE-\n" << endl;
    cout << "El discriminante(Δ) es :\n" << discriminante << endl;
    if (discriminante > 0){
        x1 = (-b + sqrt(discriminante)) /(2.0*a);
        x2 = (-b - sqrt(discriminante)) /(2.0*a);
        cout << "Discriminante > 0, existen 2 soluciones reales" << endl;
        cout << "\n -PUNTOS DE INTERSECCION DEL EJE X-\n" << endl;
        cout << fixed << setprecision(2);
        cout << "Los resultados son: x1= " << x1 << ", x2= \n" << x2 << endl;
    }
    else if( discriminante == 0){
        x3 = (-b)/(2.0*a);
        cout << "Discriminante = 0, existe 1 solucion real" << endl;
        cout << "\n -PUNTO DE INTERSECCION CON EJE X -\n" << endl;
        cout << fixed << setprecision(2);
        cout << "El resultado es: x1= \n" << x3 << endl;
    }
    else {
        cout << "Discriminante < 0, no existen soluciones reales" << endl;
    }


    vrtx = (-b)/(2.0*a);
    vrty = (-discriminante)/(4.0*a);
    cout << "\n -RESULTADO VERTICE DE LA FUNCION-\n" << endl;
    cout << fixed << setprecision(2);
    cout << "El vertice de la funcion es: (" << vrtx << "," << vrty << ")" << endl;

    return 0;     
}
