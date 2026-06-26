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

## Evolución del proyecto

### Hito 1

* **Concavidad:** Análisis de la orientación.
* **Obtención de la función:** Procesamiento de datos de entrada.
* **Discriminante:** Análisis de sus 3 casos.
* **Raíces:** Cálculo de las soluciones.
* **Vértice:** Punto del vértice.
* **Eje de simetría**.

### Hito 2

* Cambio de C a C++.
* Integración de clases, métodos y objetos.
* Grafica en consola.

### Hito 3

* Rediseño del método Calculadora para que entregue estructuras en lugar de imprimir.
* Implementación de interfaz interactiva y sencilla con Qt.
* Grafica de parábola.

---

## Clases implementadas

**Funcion:** Encapsula los coeficientes de la función.

* Su constructor ayuda a asignar los coeficientes a atributos privados.
* A(), B(), C() son getters que nos ayuda a acceder a los datos.

**Calculadora:** Obtiene los coeficientes a través de una composición con Funcion y con estos construye el objeto parábola que trabaja con los demás métodos.

* Su constructor inicializa parábola.
* CalculoDiscriminante() entrega el discriminante, da cantidad de soluciones y si estas son reales o no.
* CalculoVertice() entrega las coordenadas del vértice.
* CorteEjeY() entrega el punto donde la parábola cruza con el eje Y.
* ObtenerTabla() tabla de valores f(x) para x entre [-5, 5] .
* EvaluarFuncion(float x) evaluación puntual de f(x).

---

## Interfaz desarrollada
 
### Objetivo
Permitir que cualquier usuario ingrese los coeficientes de una función cuadrática y obtenga de forma inmediata un análisis completo con cuatro vistas complementarias: resultados algebraicos, vértice, tabla de valores y gráfica.

### Widgets principales
 
| Widget | Tipo Qt | Función |
|---|---|---|
| Campos a, b, c | QLineEdit | Ingreso de coeficientes |
| Botón Calcular | QPushButton | Dispara el cálculo (señal clicked -> slot onCalcular) |
| Pestañas | QTabWidget | Organiza las cuatro vistas |
| Labels de resultado | QLabel | Muestran discriminante, raíces, vértice, corte Y |
| Tabla de valores | QTableWidget | Muestra f(x) para x entre [-5, 5] |
| Gráfica | GraficaWidget | Dibuja la parábola con QPainter |
 

### Parametrización
El usuario ingresa los valores de a, b y c en campos de texto (QLineEdit) ubicados en la parte superior de la ventana. Al presionar el botón Calcular, se validan los valores y se procesan.
 
### Flujo de uso
1. El usuario ingresa los valores de a, b y c.
2. Presiona Calcular.
3. La aplicación valida la entrada; si hay error, muestra un QMessageBox.
4. Se usa Calculadora(a, b, c) y se invocan sus métodos.
5. Los resultados se distribuyen en las cuatro pestañas.
6. La aplicación navega automáticamente a la pestaña Gráfica.

### Pestañas
- **Discriminante:** muestra el cálculo paso a paso de Δ y las raíces reales (o aviso de raíces inexistentes).
- **Vértice y Corte Y:** coordenadas del vértice y punto de intercepto con el eje Y.
- **Tabla de valores:** tabla con f(x) evaluada en los enteros de -5 a 5.
- **Gráfica:** representación visual de la parábola con marcadores de vértice (rojo), raíces (verde) y etiquetas de coordenadas.

---

## Logica e interfaz

**funciones** se encargan de la matematica completamente, los metodos de Calculadora devuelven estructuras de datos que son utilizadas posteriormente.  
**MainWindow** solo muestra mediante widgets los datos retornados por Calculadora.  
**GraficaWidget** recibe los coeficientes, los utiliza para calcular el rango en el que la parabola quede visible y dibuja la parábola visualmente con puntos (vértices y raíces).

## Compilación y Ejecución

### Estructura de archivos fuente
src/ main.cpp  
src/mainwindow.h  
src/mainwindow.cpp  
src/funciones.h  
src/funciones.cpp  
src/graficawidget.h  
src/graficawidget.cpp  
CMakeLists.txt

### En Qt Creator
1. Abrir Qt Creator y seleccionar Abrir proyecto.
2. Seleccionar el archivo CMakeLists.txt en la raíz del repositorio.
3. Presionar Build (Ctrl+B) y luego Run (Ctrl+R).

---

## Casos de Prueba

### Una raíz (a=1, b=-4, c=4)

Resultados esperados:

* Discriminante = 0
* X = 2
* Vértice = (2,0)
<img width="898" height="528" alt="image" src="https://github.com/user-attachments/assets/fc02e8aa-b531-4673-af64-afb6a3ad57ab" />
<img width="896" height="350" alt="image" src="https://github.com/user-attachments/assets/1de5aeb9-1a6e-4aad-9f5b-06de1a4bd461" />
<img width="903" height="326" alt="image" src="https://github.com/user-attachments/assets/7332be2a-ad9b-448f-86d0-a7390d6e87dc" />
<img width="903" height="523" alt="image" src="https://github.com/user-attachments/assets/c17680b1-78a1-4150-9927-b52ca64ddaf8" />

### Sin raíces reales (a=1, b=0, c=4)

* Discriminante = -16
* No existen soluciones reales
* Vértice = (-1,4)
<img width="897" height="528" alt="image" src="https://github.com/user-attachments/assets/822f0cb6-404d-4e09-8f43-ece58c6d8792" />
<img width="898" height="356" alt="image" src="https://github.com/user-attachments/assets/b307ca15-151e-49cb-9725-257a2dae68cd" />
<img width="900" height="340" alt="image" src="https://github.com/user-attachments/assets/0a0ef1fc-5dd6-4f1d-b086-34eb5c8f67d0" />
<img width="903" height="531" alt="image" src="https://github.com/user-attachments/assets/fc7dc7c0-2573-472d-b63f-6b8862f3a677" />

### Parábola invertida (a=-1, b=2, c=3)

Resultados esperados:

* Parábola abre hacia abajo.
* Discriminante =16
* X1 = 3, X2 = -1
* La gráfica debe verse invertida.
<img width="901" height="532" alt="image" src="https://github.com/user-attachments/assets/63635ca8-11a4-4378-9e85-4a7d881f31cc" />
<img width="902" height="347" alt="image" src="https://github.com/user-attachments/assets/1806d604-4010-41b3-aec6-116a7c262673" />
<img width="902" height="330" alt="image" src="https://github.com/user-attachments/assets/33165c51-3b8a-4fcf-afca-a5f6bcbdc0d4" />
<img width="902" height="536" alt="image" src="https://github.com/user-attachments/assets/672e647b-b0d2-466f-a9fe-1c4391074a2d" />


### Validación (a=0)

Resultados esperados:
Un QMessageBox indicando que a no puede ser cero.  

<img width="391" height="165" alt="image" src="https://github.com/user-attachments/assets/9f3dd046-3c12-40ed-b98b-aac5948c6227" />


### Entrada no numerica

Resultados esperados:
Un QMessageBox indicando que los valores deben ser numéricos.
<img width="475" height="165" alt="image" src="https://github.com/user-attachments/assets/121c1599-cc13-40ff-bc4c-6ee3b6a22ef8" />

---

## Principales dificultades

* Compatibilidad con la paleta de colores de defecto de Qt.
* Calcular automáticamente los rangos para la visualización de la parábola.

## Conclusiones
El proyecto cumplió su objetivo de construir una herramienta pedagógica que hace visible la relación entre los coeficientes algebraicos y el comportamiento gráfico de la función cuadrática. El diseño orientado a objetos, establecido desde el Hito 2, facilitó la integración de la interfaz gráfica en el Hito 3 al tener la lógica matemática encapsulada en Calculadora y Funcion, MainWindow pudo conectarse a ella sin modificar ningún cálculo existente, lo que redujo errores, mantuvo el código organizado y nos enseño la muy buena practica de separar logica de interfaz. Si el proyecto continuara en desarrollo lo que añadiriamos un modo de explicación paso a paso animado para cada cálculo ,ya que es lo más complejo de entender de la función cuadrática.  

## Referencias

* MathIsFun — Quadratic Equation: https://www.mathsisfun.com/algebra/quadratic-equation.html
* Qt Documentation — Qt Widgets: https://doc.qt.io/qt-6/qtwidgets-index.html
* Qt Documentation — Signals & Slots: https://doc.qt.io/qt-6/signalsandslots.html
* Qt Documentation — QPainter: https://doc.qt.io/qt-6/qpainter.html
