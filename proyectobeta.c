#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, dis, x1, x2, x3, ejey;
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
    dis = (b*b) - (4*a*c);
    printf("\n---RESULTADO DEL DISCRIMINANTE(Δ)---\n");
    printf("El discriminante(Δ) es: %2.f \n", dis);
    if ( dis > 0 ){
        x1= (-b + sqrt(dis)) /(2.0*a);
        x2= (-b - sqrt(dis)) /(2.0*a);
        printf("\n---RESULTADO DEL PUNTO QUE TOCA EN EL EJE X---\n");
        printf("Discriminante > 0 --> 2 soluciones reales \n");
        printf("x1 = %.2f, x2 = %.2f\n", x1,x2);  
    }
    else if ( dis == 0 ){
        x3 = (-b)/(2.0*a);
        printf("Discriminante = 0 --> 1 solucion real \n");
        printf("\n---RESULTADO DEL PUNTO QUE TOCA EN EL EJE X---\n");
        printf("x1= %.2f\n", x3);
    }
    else {
        printf("Discriminante < 0 --> sin soluciones reales\n");
    }
    float vrtx, vrty;
    //int det2;
    //det2 = (b*b)-(4*a*c);
    vrtx = (-b/(2*a));
    vrty = -dis/(4*a);
    printf("\n---RESULTADO DEL VERTICE DE LA FUNCION---\n");
    printf("El vertice se encuentra en %.2f ,%.2f \n", vrtx,vrty);
    printf("\n---RESULTADO CORTE DE LA FUNCION EN EJE Y---\n");
    printf("(0,%2.f)\n", c);
    printf("¿Te interesa saber como se calcula?(1.Si)(2.No)\n");
    scanf("%f", &ejey);
    if ( ejey == 1 ){
        printf("Tenemos que igualar x = 0 en la funcion, esto nos dejara un resultado y este vendria siendo nuestra coordenada Y, la cual resprensentamos de la forma (0,c)\n");
    }  
    else{
        printf("Ok");
    }    return 0;
}