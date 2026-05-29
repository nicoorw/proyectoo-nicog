# Analizador Pedagógico de Funciones Cuadráticas

# Resumen de la problemática a solucionar
La función cuadrática es una de las funciones que mas se malentiende ya que solo se enseña a través de formulas, pero nunca el que representan estas o como se obtienen, se memoriza, pero no se entiende.

## Objetivo general del proyecto
Desarrollar una herramienta computacional educativa que, entregue el análisis completo de una función cuadrática de manera clara, ordenada y pedagógica.

## Objetivos específicos
* Analizar funciones cuadráticas a partir del ingreso de sus coeficientes desde la consola.
* Aplicar los conceptos matemáticos asociados a las funciones cuadráticas para obtener información.
* Interpretar los valores de una función cuadrática con el fin de determinar el comportamiento.
* Representar de manera clara y estructurada los distintos elementos que describen una función cuadrática.
* Apoyar el aprendizaje de funciones cuadráticas mediante el uso de una herramienta computacional interactiva.

## Roles de cada integrante 
* **Nicolás Currimán->** Desarrollo principal.
* **Nicolás Cabezas->** Pruebas y organización del proyecto.
* **Francisca Koweil->** Lógica matemática y Validación Pedagógica.
* **Fernanda Urra->** Documentación y Estructura.

---

## Funcionalidades implementadas  

**PedirCoeficientes:** Se encarga de obtener los coeficientes y se asegura de que tenga valores validos.
**ExplicarFuncionCuadratica:** Imprime un mensaje de bienvenida y explica la forma general.  

## Clases implementadas

**Funcion:**Guarda y expone los coeficientes.
- Su constructor ayuda a asignar los coeficientes a atributos privados.
- A(), B(), C() nos ayuda a acceder a los datos.

**Calculadora:** Obtiene los coeficientes a traves de una composicion con Funcion y con estos construye el objeto parabola que trabaja con los demas metodos.
- Su constructor inicializa parabola.
- CalculoDiscriminante() entrega el discriminante, da cantidad de soluciones y si estas son reales o no.
- CalculoVertice(float dis) imprime las coordenadas del vertice.
- CorteEjeY() imprime el punto donde la parabola cruza con el eje y.
- MostrarTabla() calcula f(x) en un intervalo de -5 a 5.
- GraficarConsola() representa la parabola en la consola.

## Cambios estructurales de C a C++
- Paso de funciones a métodos.
- Manejo de objetos, sus datos (atributos) y comportamientos (métodos).


## Compilación y Ejecución   
g++ main.cpp funciones.cpp -o proyecto -lm  
./proyecto

## Casos de Prueba  

## Principales dificultades  
- Desarrollar una composicion.
- Graficar una parabola en consola.

---
## Avance logrado (Hito 1)
* **Concavidad:** Análisis de la orientación.
* **Obtención de la función:** Procesamiento de datos de entrada.
* **Discriminante:** Análisis de sus 3 casos.
* **Raíces:** Cálculo de las soluciones.
* **Vértice:** Punto del vértice.
* **Eje de simetría**.

## Avance Hito 2  
* **Cambio de C a C++**
* ** **

## Próximos pasos
* Avance hacia el **Hito 2**.
  - La implementación de la interfaz gráfica con fines pedagógicos.
  - Expandir el análisis matemático de la función.
  - Profundizaremos en el carácter pedagógico.
 
* Avance hacia el **Hito 3**.
  - Implementacion de grafica de función interactiva con Qt.

## Referencias  
- https://www.mathsisfun.com/algebra/quadratic-equation.html
