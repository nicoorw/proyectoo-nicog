#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include "funciones.h"
#include "graficawidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCalcular();

private:
    QLineEdit *inputA;
    QLineEdit *inputB;
    QLineEdit *inputC;
    QPushButton *btnCalcular;

    QTabWidget *tabWidget;

    QLabel *lblDiscriminante;
    QLabel *lblRaices;

    QLabel *lblVertice;
    QLabel *lblCorteY;

    QTableWidget *tablaValores;

    GraficaWidget *graficaWidget;

    void construirUI();
    QWidget* crearPestaniaDiscriminante();
    QWidget* crearPestaniaVertice();
    QWidget* crearPestaniaTabla();
    QWidget* crearPestaniaGrafica();

    void llenarTabla(const std::vector<std::pair<float,float>> &datos);
};

#endif // MAINWINDOW_H