#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, det, x1, x2, x3, ejey;
    printf("Ingresa los valores de la funcion de forma tal que ax² + bx + c\n");
    printf("Ingresa el valor de la variable a: \n");
    scanf("%f", &a);
    if ( a == 0 ){
        printf("La funcion no es cuadratica\n");
        return 0;
    }
    printf("Ingresa el valor de la variable b: \n");
    scanf("%f", &b);
    printf("Ingresa el valor de la variable c: \n");
    scanf("%f", &c);
    det = (b*b) - (4*a*c);
    printf("\n---RESULTADO DEL DISCRIMINANTE---\n");
    printf("El discriminante es: %2.f \n", det);
    if ( det > 0 ){
        x1= (-b + sqrt(det)) /(2.0*a);
        x2= (-b - sqrt(det)) /(2.0*a);
        printf("\n---RESULTADO DEL PUNTO QUE TOCA EN EL EJE X---\n");
        printf("Discriminante > 0 --> 2 soluciones reales \n");
        printf("x1 = %.2f, x2 = %.2f\n", x1,x2);  
    }
    else if ( det == 0 ){
        x3 = (-b)/(2.0*a);
        printf("Discriminante = 0 --> 1 solucion real \n");
        printf("\n---RESULTADO DEL PUNTO QUE TOCA EN EL EJE X---\n");
        printf("x1= %.2f\n", x3);
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



    
    
    
    
    
    
    printf("\n---RESULTADO CORTE DE LA FUNCION EN EJE Y---\n");
    printf("(0,%2.f)\n", c);
    printf("¿Te interesa saber como se calcula?(1.Si)(2.No)\n");
    scanf("%f", &ejey);
    if ( ejey == 1 ){
        printf("Tenemos que igualar x = 0 en la funcion, esto nos dejara un resultado y este vendria siendo nuestra coordenada Y, la cual resprensentamos de la forma (0,c)\n");
    }  
    else{
        printf("Jodete");
    }    return 0;
}