#ifndef GRAFICAWIDGET_H
#define GRAFICAWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QColor>
#include "funciones.h"

class GraficaWidget : public QWidget {
    Q_OBJECT

public:
    explicit GraficaWidget(QWidget *parent = nullptr);

    // Carga los coeficientes y repinta el widget
    void setCoeficientes(float a, float b, float c);

protected:
    // Qt llama a este metodo cada vez que hay que redibujar
    void paintEvent(QPaintEvent *event) override;

private:
    float coef_a;
    float coef_b;
    float coef_c;
    bool hayFuncion; // false hasta que el usuario ingrese coeficientes

    // Convierte coordenadas matematicas a pixeles de pantalla
    QPointF matematicaAPixel(float x, float y,
                              float xMin, float xMax,
                              float yMin, float yMax,
                              int W, int H, int margen) const;

    void dibujarEjes(QPainter &p, float xMin, float xMax,
                     float yMin, float yMax,
                     int W, int H, int margen);

    void dibujarParabola(QPainter &p, float xMin, float xMax,
                         float yMin, float yMax,
                         int W, int H, int margen);

    void dibujarVertice(QPainter &p, float xMin, float xMax,
                        float yMin, float yMax,
                        int W, int H, int margen);

    void dibujarRaices(QPainter &p, float xMin, float xMax,
                       float yMin, float yMax,
                       int W, int H, int margen);
};

#endif // GRAFICAWIDGET_H
