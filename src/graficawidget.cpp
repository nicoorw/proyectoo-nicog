#include "graficawidget.h"
#include <QPainterPath>
#include <QFontMetrics>
#include <cmath>

GraficaWidget::GraficaWidget(QWidget *parent)
    : QWidget(parent), coef_a(1), coef_b(0), coef_c(0), hayFuncion(false) {
    setMinimumSize(400, 350);
    // Fondo blanco
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
}

void GraficaWidget::setCoeficientes(float a, float b, float c) {
    coef_a = a;
    coef_b = b;
    coef_c = c;
    hayFuncion = true;
    update(); // Dispara paintEvent
}

// Convierte un punto matematico (x,y) a coordenadas de pixel en el widget
QPointF GraficaWidget::matematicaAPixel(float x, float y,
                                         float xMin, float xMax,
                                         float yMin, float yMax,
                                         int W, int H, int margen) const {
    float px = margen + (x - xMin) / (xMax - xMin) * (W - 2 * margen);
    float py = H - margen - (y - yMin) / (yMax - yMin) * (H - 2 * margen);
    return QPointF(px, py);
}

void GraficaWidget::dibujarEjes(QPainter &p, float xMin, float xMax,
                                  float yMin, float yMax,
                                  int W, int H, int margen) {
    QPen ejesPen(QColor(80, 80, 80), 2);
    p.setPen(ejesPen);

    // Eje X: y = 0
    if (yMin <= 0 && yMax >= 0) {
        QPointF inicio = matematicaAPixel(xMin, 0, xMin, xMax, yMin, yMax, W, H, margen);
        QPointF fin    = matematicaAPixel(xMax, 0, xMin, xMax, yMin, yMax, W, H, margen);
        p.drawLine(inicio, fin);
        // Flecha eje X
        p.drawLine(fin, QPointF(fin.x() - 8, fin.y() - 5));
        p.drawLine(fin, QPointF(fin.x() - 8, fin.y() + 5));
        p.setFont(QFont("Arial", 10, QFont::Bold));
        p.drawText(QPointF(fin.x() + 4, fin.y() + 5), "x");
    }

    // Eje Y: x = 0
    if (xMin <= 0 && xMax >= 0) {
        QPointF inicio = matematicaAPixel(0, yMin, xMin, xMax, yMin, yMax, W, H, margen);
        QPointF fin    = matematicaAPixel(0, yMax, xMin, xMax, yMin, yMax, W, H, margen);
        p.drawLine(inicio, fin);
        // Flecha eje Y
        p.drawLine(fin, QPointF(fin.x() - 5, fin.y() + 8));
        p.drawLine(fin, QPointF(fin.x() + 5, fin.y() + 8));
        p.setFont(QFont("Arial", 10, QFont::Bold));
        p.drawText(QPointF(fin.x() + 4, fin.y()), "y");
    }

    // Marcas y numeros en eje X
    QPen marcaPen(QColor(180, 180, 180), 1);
    p.setPen(marcaPen);
    p.setFont(QFont("Arial", 7));
    for (int xi = (int)std::ceil(xMin); xi <= (int)std::floor(xMax); xi++) {
        if (xi == 0) continue;
        QPointF pt = matematicaAPixel(xi, 0, xMin, xMax, yMin, yMax, W, H, margen);
        // Linea de grilla vertical tenue
        p.drawLine(QPointF(pt.x(), margen), QPointF(pt.x(), H - margen));
        p.setPen(QColor(80, 80, 80));
        p.drawLine(QPointF(pt.x(), pt.y() - 4), QPointF(pt.x(), pt.y() + 4));
        p.drawText(QPointF(pt.x() - 5, pt.y() + 14), QString::number(xi));
        p.setPen(marcaPen);
    }

    // Marcas y numeros en eje Y
    int paso = std::max(1, (int)((yMax - yMin) / 8));
    for (int yi = (int)std::ceil(yMin / paso) * paso; yi <= (int)(yMax); yi += paso) {
        if (yi == 0) continue;
        QPointF pt = matematicaAPixel(0, yi, xMin, xMax, yMin, yMax, W, H, margen);
        p.drawLine(QPointF(margen, pt.y()), QPointF(W - margen, pt.y()));
        p.setPen(QColor(80, 80, 80));
        p.drawLine(QPointF(pt.x() - 4, pt.y()), QPointF(pt.x() + 4, pt.y()));
        p.drawText(QPointF(pt.x() + 6, pt.y() + 4), QString::number(yi));
        p.setPen(marcaPen);
    }

    // Origen (0,0)
    QPointF origen = matematicaAPixel(0, 0, xMin, xMax, yMin, yMax, W, H, margen);
    p.setPen(QColor(80, 80, 80));
    p.setFont(QFont("Arial", 7));
    p.drawText(QPointF(origen.x() + 4, origen.y() + 12), "0");
}

void GraficaWidget::dibujarParabola(QPainter &p, float xMin, float xMax,
                                     float yMin, float yMax,
                                     int W, int H, int margen) {
    QPainterPath path;
    int pasos = 300;
    float step = (xMax - xMin) / pasos;
    bool primero = true;

    for (int i = 0; i <= pasos; i++) {
        float x = xMin + i * step;
        float y = coef_a * x * x + coef_b * x + coef_c;

        // Solo dibuja si y esta dentro del rango visible
        if (y < yMin || y > yMax) {
            primero = true;
            continue;
        }

        QPointF pt = matematicaAPixel(x, y, xMin, xMax, yMin, yMax, W, H, margen);
        if (primero) {
            path.moveTo(pt);
            primero = false;
        } else {
            path.lineTo(pt);
        }
    }

    // Parabola en azul
    QPen parabolaPen(QColor(30, 100, 220), 2.5);
    p.setPen(parabolaPen);
    p.setBrush(Qt::NoBrush);
    p.drawPath(path);
}

void GraficaWidget::dibujarVertice(QPainter &p, float xMin, float xMax,
                                    float yMin, float yMax,
                                    int W, int H, int margen) {
    float vx = -coef_b / (2.0f * coef_a);
    float disc = coef_b * coef_b - 4.0f * coef_a * coef_c;
    float vy = -disc / (4.0f * coef_a);

    if (vx < xMin || vx > xMax || vy < yMin || vy > yMax) return;

    QPointF pt = matematicaAPixel(vx, vy, xMin, xMax, yMin, yMax, W, H, margen);

    // Punto rojo para el vertice
    p.setPen(QPen(QColor(200, 0, 0), 2));
    p.setBrush(QColor(200, 0, 0));
    p.drawEllipse(pt, 5, 5);

    // Etiqueta del vertice
    p.setFont(QFont("Arial", 8));
    p.setPen(QColor(180, 0, 0));
    QString label = QString("V(%1, %2)")
                        .arg(vx, 0, 'f', 2)
                        .arg(vy, 0, 'f', 2);
    p.drawText(QPointF(pt.x() + 7, pt.y() - 5), label);
}

void GraficaWidget::dibujarRaices(QPainter &p, float xMin, float xMax,
                                   float yMin, float yMax,
                                   int W, int H, int margen) {
    float disc = coef_b * coef_b - 4.0f * coef_a * coef_c;
    if (disc < 0) return;

    auto marcarRaiz = [&](float rx) {
        if (rx < xMin || rx > xMax) return;
        float ry = 0;
        if (ry < yMin || ry > yMax) return;
        QPointF pt = matematicaAPixel(rx, ry, xMin, xMax, yMin, yMax, W, H, margen);
        p.setPen(QPen(QColor(0, 160, 0), 2));
        p.setBrush(QColor(0, 160, 0));
        p.drawEllipse(pt, 5, 5);
        p.setFont(QFont("Arial", 8));
        p.setPen(QColor(0, 130, 0));
        QString label = QString("x=%1").arg(rx, 0, 'f', 2);
        p.drawText(QPointF(pt.x() + 6, pt.y() - 6), label);
    };

    if (disc == 0) {
        float x1 = -coef_b / (2.0f * coef_a);
        marcarRaiz(x1);
    } else {
        float x1 = (-coef_b + std::sqrt(disc)) / (2.0f * coef_a);
        float x2 = (-coef_b - std::sqrt(disc)) / (2.0f * coef_a);
        marcarRaiz(x1);
        marcarRaiz(x2);
    }
}

void GraficaWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int W = width();
    int H = height();
    int margen = 45;

    // Fondo blanco
    p.fillRect(rect(), Qt::white);

    if (!hayFuncion) {
        p.setPen(QColor(150, 150, 150));
        p.setFont(QFont("Arial", 12));
        p.drawText(rect(), Qt::AlignCenter, "Ingresa los coeficientes\ny presiona Calcular");
        return;
    }

    // Calcula el rango de x e y automaticamente
    float xMin = -7.0f, xMax = 7.0f;

    // Evalua f(x) en varios puntos para determinar rango y
    float yMin = coef_a * xMin * xMin + coef_b * xMin + coef_c;
    float yMax = yMin;
    int pasos = 200;
    for (int i = 0; i <= pasos; i++) {
        float x = xMin + i * (xMax - xMin) / pasos;
        float y = coef_a * x * x + coef_b * x + coef_c;
        if (y < yMin) yMin = y;
        if (y > yMax) yMax = y;
    }

    // Agrega margen vertical para que no quede al borde
    float rangoY = yMax - yMin;
    if (rangoY < 1.0f) rangoY = 1.0f;
    yMin -= rangoY * 0.2f;
    yMax += rangoY * 0.2f;

    // Asegura que el eje X sea visible
    if (yMin > 0)  yMin = -rangoY * 0.1f;
    if (yMax < 0)  yMax =  rangoY * 0.1f;

    dibujarEjes(p, xMin, xMax, yMin, yMax, W, H, margen);
    dibujarParabola(p, xMin, xMax, yMin, yMax, W, H, margen);
    dibujarVertice(p, xMin, xMax, yMin, yMax, W, H, margen);
    dibujarRaices(p, xMin, xMax, yMin, yMax, W, H, margen);

    // Titulo de la funcion
    p.setFont(QFont("Arial", 9, QFont::Bold));
    p.setPen(QColor(30, 30, 30));
    QString titulo;
    if (coef_b >= 0 && coef_c >= 0)
        titulo = QString("f(x) = %1x² + %2x + %3").arg(coef_a).arg(coef_b).arg(coef_c);
    else if (coef_b < 0 && coef_c >= 0)
        titulo = QString("f(x) = %1x² - %2x + %3").arg(coef_a).arg(std::abs(coef_b)).arg(coef_c);
    else if (coef_b >= 0 && coef_c < 0)
        titulo = QString("f(x) = %1x² + %2x - %3").arg(coef_a).arg(coef_b).arg(std::abs(coef_c));
    else
        titulo = QString("f(x) = %1x² - %2x - %3").arg(coef_a).arg(std::abs(coef_b)).arg(std::abs(coef_c));
    p.drawText(QRect(margen, 5, W - 2 * margen, 20), Qt::AlignCenter, titulo);
}
