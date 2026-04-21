#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c, det;
    double x1, x2, x3;
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
    if (det>0){
        x1= (-b+sqrt(det))/(2.0*a);
        x2= (-b-sqrt(det)/(2.0*a));
        printf("Discriminante > 0 --> 2 soluciones reales \n");
        printf("x1 = %.2lf, x2 = %.2lf\n", x1,x2);  
    }
    else if (det == 0){
        x3 = (-b)/(2.0*a);
        printf("Discriminante = 0 --> 1 solucion real \n");
        printf("x1= %.2lf\n", x3);
    }
    else {
        printf("Discriminante < 0 --> sin soluciones reales\n");
    }

    printf("Para saber el corte de la funcion con el eje Y (eje vertical) tenemos que: \n");
    printf("El corte del eje Y seria (0,c), dejando como valor fijo x = 0, en este caso el corte seria (0,%d) \n", c);

    float vrtx, vrty;
    int det2;
    det2 = (b*b)-(4*a*c);
    vrtx = (-b/(2*a));
    vrty = -det2/(4*a);
    
    printf("El vertice se encuentra en %.1f ,%.1f \n", vrtx,vrty);



    
    
    
    
    
    
    
    
    

    
    
    return 0;


}