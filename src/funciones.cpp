#include "funciones.h"

Funcion::Funcion(float a, float b, float c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
float Funcion::A() {
    return a;
}
float Funcion::B() {
    return b;
}
float Funcion::C() {
    return c;
}
Calculadora::Calculadora(float a, float b, float c): parabola(a,b,c){
}

// Explica al usuario en que consiste una funcion cuadratica antes de comenzar
void ExplicarFuncionCuadratica(){
    std::cout << "Bienvenido a la calculadora de funciones cuadraticas\n";
    std::cout << "Una funcion cuadratica tiene la forma: f(x) = ax^2 + bx + c\n";
}

// Pide al usuario los coeficientes a, b, c de la funcion cuadratica
// Valida que a sea distinto de 0 y confirma que la funcion ingresada es correcta
void PedirCoeficientes(float &a, float &b, float &c){
    std::string consultafun;
    do {
        std::cout << "La funcion cuadratica esta compuesta de forma tal que:\n";
        std::cout << "f(x) = ax^2 + bx + c\n";
        std::cout << "Ingresa el valor de a: ";
        std::cin >> a;
        // a no puede ser 0 porque dejaria de ser cuadratica
        if (a == 0) {
            std::cout << "La funcion no es cuadratica, porque a debe ser distinto de 0.\n";
            std::cout << "Ingresa nuevamente el valor de a.\n";
        }
    } 
    while (a == 0);
    std::cout << "Ingresa el valor de b: \n";
    std::cin >> b;
    std::cout << "Ingresa el valor de c: \n";
    std::cin >> c;
    // Muestra la funcion ingresada con el signo correcto segun el valor de b y c
    std::cout << "La funcion a trabajar seria: \n";
    std::cout << a << "x^2";
    if (b > 0) {
        std::cout << " + " << b << "x";
    } else if (b < 0) {
        std::cout << " - " << std::abs(b) << "x";
    }
    if (c > 0) {
        std::cout << " + " << c;
    } else if (c < 0) {
        std::cout << " - " << std::abs(c);
    }
    std::cout << std::endl;
    // Confirmacion del usuario antes de continuar
    std::cout << "La funcion es correcta? Escribe si o no: \n";
    std::cin >> consultafun;
    while (consultafun != "si" && consultafun != "Si" && consultafun != "SI" && consultafun != "sii" && consultafun != "SII" && consultafun != "sip") {
        std::cout << "Ingresa nuevamente los valores.\n";
        PedirCoeficientes(a, b, c);
        return;
    }
    std::cout << "Entonces seguimos con los calculos.\n";
}

// Calcula el discriminante de la funcion cuadratica
// Segun su valor determina si hay 2, 1 o 0 soluciones reales
// Retorna el discriminante para usarlo en otras funciones
float Calculadora::CalculoDiscriminante (){
    float discriminante, x1, x2, x3;
    // Formula del discriminante: b^2 - 4ac
    float a= parabola.A();
    float b= parabola.B();  
    float c= parabola.C();
    discriminante = (b*b)-(4.0*a*c);
    std::cout << "\n===============================\n" << std::endl;
    std::cout << "\n -RESULTADO DEL DISCRIMINANTE- \n" << std::endl;
    std::cout << "\n================================\n" << std::endl;
    std::cout << "El discriminante(Delta) es :\n" << discriminante << std::endl;
    if (discriminante > 0){
        // Dos soluciones reales: formula cuadratica con + y -
        x1 = (-b + sqrt(discriminante)) /(2.0*a);
        x2 = (-b - sqrt(discriminante)) /(2.0*a);
        std::cout << "Discriminante > 0, existen 2 soluciones reales" << std::endl;
        std::cout << "\n -PUNTOS DE INTERSECCION DEL EJE X-\n" << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Los resultados son: x1= " << x1 << ", x2= " << x2 << std::endl;
    }
    else if( discriminante == 0){
        // Una solucion real: la parabola toca el eje x en un solo punto
        x3 = (-b)/(2.0*a);
        std::cout << "Discriminante = 0, existe 1 solucion real" << std::endl;
        std::cout << "\n -PUNTO DE INTERSECCION CON EJE X -\n" << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "El resultado es: x1= \n" << x3 << std::endl;
    }
    else {
        // Sin soluciones reales: la parabola no toca el eje x
        std::cout << "Discriminante < 0, no existen soluciones reales" << std::endl;
    }
    return discriminante;
}

// Calcula el vertice de la parabola usando las formulas:
// vrtx = -b / (2a)
// vrty = -discriminante / (4a)
void Calculadora::CalculoVertice(float dis){
    float a= parabola.A();
    float b= parabola.B();
    float vrtx, vrty;
    vrtx = (-b/(2*a));
    vrty = -dis/(4*a);
    std::cout << "\n---RESULTADO DEL VERTICE DE LA FUNCION---\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "El vertice se encuentra en " << vrtx << " ," << vrty << std::endl;
}

// Muestra el punto donde la funcion corta el eje Y
// El corte en Y siempre es (0, c) porque cuando x=0, f(0) = c
void Calculadora::CorteEjeY(){
    float c= parabola.C();
    int expl;
    std::cout << "\n---CORTE DE LA FUNCION EN EJE Y---\n";
    std::cout << "El corte del eje Y es: (0," << c << ")\n";
    std::cout << "¿Te interesa saber como se calcula?(1.Si)(2.No)\n";
    std::cin >> expl;
    if ( expl == 1 ){
        std::cout << "Tenemos que igualar x = 0 en la funcion, esto nos dejara un resultado y este vendria siendo nuestra coordenada Y, por lo tanto se representa como (0,c)\n";
    }  
    else{
        std::cout << "Ok\n";
    }
}

// Muestra una tabla con los valores de f(x) para x entre -5 y 5
void Calculadora::MostrarTabla(){
    float a= parabola.A();
    float b= parabola.B();
    float c= parabola.C();
    std::cout << "\n---TABLA DE VALORES---\n";
    std::cout << std::setw(10) << "x" << std::setw(15) << "f(x)" << std::endl;
    std::cout << "------------------------------\n";
    for (int x = -5; x <= 5; x++) {
        // Calcula f(x) = ax^2 + bx + c para cada valor de x
        float fx = a*(x*x) + b*x + c;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(10) << x << std::setw(15) << fx << std::endl;
    }
}

// Genera una representacion grafica aproximada de la funcion en consola
// Usa asteriscos para mostrar la posicion de f(x) en cada fila
void Calculadora::GraficarConsola(){
    float a= parabola.A();
    float b= parabola.B();
    float c= parabola.C();
    std::cout << "\n---GRAFICA EN CONSOLA---\n";
    // Primero calcula el maximo y minimo para escalar el grafico
    float maxVal = a*((-5)*(-5)) + b*(-5) + c;
    float minVal = maxVal;
    for (int x = -5; x <= 5; x++) {
        float fx = a*(x*x) + b*x + c;
        if (fx > maxVal) maxVal = fx;
        if (fx < minVal) minVal = fx;
    }
    int anchura = 40; // ancho del grafico en caracteres
    for (int x = -5; x <= 5; x++) {
        float fx = a*(x*x) + b*x + c;
        std::cout << std::setw(3) << x << " | ";
        // Calcula la posicion del asterisco proporcionalmente al rango de valores
        int pos = 0;
        if (maxVal != minVal) {
            pos = (int)((fx - minVal) / (maxVal - minVal) * anchura);
        } else {
            pos = anchura / 2;
        }
        for (int i = 0; i < anchura; i++) {
            if (i == pos) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << "  f(" << x << ")=" << std::fixed << std::setprecision(2) << fx << std::endl;
    }
}
