# Analizador Pedagógico de Funciones Cuadráticas

# Resumen de la problemática a solucionar
La función cuadrática es una de las funciones que más se malentiende ya que solo se enseña a través de fórmulas, pero nunca lo que representan estas o cómo se obtienen, se memoriza, pero no se entiende.

## Objetivo general del proyecto
Desarrollar una herramienta computacional educativa que entregue el análisis completo de una función cuadrática de manera clara, ordenada y pedagógica.

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

**PedirCoeficientes:** Se encarga de obtener los coeficientes y se asegura de que tenga valores válidos.
**ExplicarFuncionCuadratica:** Imprime un mensaje de bienvenida y explica la forma general.  

## Clases implementadas

**Funcion:** Guarda y expone los coeficientes.
- Su constructor ayuda a asignar los coeficientes a atributos privados.
- A(), B(), C() nos ayuda a acceder a los datos.

**Calculadora:** Obtiene los coeficientes a través de una composición con Funcion y con estos construye el objeto parábola que trabaja con los demás métodos.
- Su constructor inicializa parábola.
- CalculoDiscriminante() entrega el discriminante, da cantidad de soluciones y si estas son reales o no.
- CalculoVertice(float dis) imprime las coordenadas del vértice.
- CorteEjeY() imprime el punto donde la parábola cruza con el eje Y.
- MostrarTabla() calcula f(x) en un intervalo de -5 a 5.
- GraficarConsola() representa la parábola en la consola.

## Cambios estructurales de C a C++
- Paso de funciones a métodos.
- Manejo de objetos, sus datos (atributos) y comportamientos (métodos).


## Compilación y Ejecución   
g++ main.cpp funciones.cpp -o proyecto -lm  
./proyecto

## Casos de Prueba  
### Una raíz  
Resultados esperados:   
  - Discriminante = 0
  - x = 2
  - Vértice = (2,0)
<img width="1547" height="3242" alt="image" src="https://github.com/user-attachments/assets/bebe5044-b498-4f2e-bfb5-85f0b6981a1d" />

### Parábola invertida
Resultados esperados:  
  - Parábola abre hacia abajo.
  - Discriminante positivo.
  - Tabla y gráfica deben verse invertidas.
<img width="1548" height="3236" alt="image" src="https://github.com/user-attachments/assets/4d58c45d-0bf8-45d5-8be9-f22a1c90d60b" />

### Sin raíces reales
  - Discriminante = -16
  - No existen soluciones reales
  - Vértice = (-1,4)
<img width="1550" height="3116" alt="image" src="https://github.com/user-attachments/assets/5dfec136-7183-4613-903d-9d0a1be3896f" />

### a=0
<img width="1516" height="263" alt="image" src="https://github.com/user-attachments/assets/cb0e6da7-2937-49ad-9c11-decad95816b3" />


## Principales dificultades  
- Desarrollar una composición.
- Graficar una parábola en consola.

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
  - Implementación de gráfica de función interactiva con Qt.
  - Soluciones complejas.
  - Generar un reporte.

## Referencias  
- https://www.mathsisfun.com/algebra/quadratic-equation.html
