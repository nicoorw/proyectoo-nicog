#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    int det;
    double x1, x2;
    printf("Ingresa los valores de la funcion de forma tal que ax² + bx + c\n");
    printf("Ingresa el valor de la variable a: \n");
    scanf("%d", &a);
    if (a == 0){
        printf("La funcion no es cuadratica\n");
        return 0;
    }
    printf("Ingresa el valor de la variable b: \n");
    scanf("%d", &b);
    printf("Ingresa el valor de la variable c: \n");
    scanf("%d", &c);
    det = (b*b)-(4*a*c);
    printf("El discriminante es: %d \n", det);
    x1= (-b+sqrt(det))/(2*a);
    x2= (-b-sqrt(det))/(2*a);
    if (det>0){
        x1= (-b+sqrt((b*b)-(4*a*c)))/(2*a);
        x2= (-b-sqrt((b*b)-(4*a*c)))/(2*a);
        printf("Ya que tenemos nuestro discriminante > 0, existen 2 soluciones reales: \n");
        printf("x1 = %2lf, x2 = %2lf", x1,x2);
    }
    else if (det == 0){
        printf("La parabola corta en 1 punto al eje x\n");
    }
    else {
        printf("No hay soluciones reales\n");
    }



    
    
    
    
    
    
    
    
    
    
    
    return 0;

}