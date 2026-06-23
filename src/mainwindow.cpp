#include "mainwindow.h"
#include <QMainWindow>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Calculadora de Funciones Cuadráticas");
    setMinimumSize(750, 580);
    construirUI();
}

MainWindow::~MainWindow() {}

void MainWindow::construirUI() {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout(central);
    layoutPrincipal->setSpacing(10);
    layoutPrincipal->setContentsMargins(15, 15, 15, 15);

    QLabel *titulo = new QLabel("Calculadora de Funciones Cuadráticas");
    titulo->setAlignment(Qt::AlignCenter);
    titulo->setStyleSheet("font-size: 18px; font-weight: bold; color: #1a3a6e; padding: 6px;");
    layoutPrincipal->addWidget(titulo);

    QLabel *subtitulo = new QLabel("f(x) = ax² + bx + c");
    subtitulo->setAlignment(Qt::AlignCenter);
    subtitulo->setStyleSheet("font-size: 13px; color: #555; margin-bottom: 4px;");
    layoutPrincipal->addWidget(subtitulo);

    QGroupBox *grupoEntrada = new QGroupBox("Ingresa los coeficientes");
    grupoEntrada->setStyleSheet(
        "QGroupBox { font-weight: bold; font-size: 12px; border: 1.5px solid #4a90d9;"
        "border-radius: 6px; margin-top: 8px; padding: 8px; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 4px; color: #1a3a6e; }"
        );

    QHBoxLayout *layoutEntrada = new QHBoxLayout(grupoEntrada);

    QString labelStyle = "font-size: 12px; font-weight: bold; color: #333;";
    QString inputStyle = "font-size: 13px; padding: 4px 8px; border: 1.5px solid #aaa;"
                         "border-radius: 4px; min-width: 70px; max-width: 100px;";

    QLabel *lblA = new QLabel("a =");
    lblA->setStyleSheet(labelStyle);
    inputA = new QLineEdit("1");
    inputA->setStyleSheet(inputStyle);

    QLabel *lblB = new QLabel("b =");
    lblB->setStyleSheet(labelStyle);
    inputB = new QLineEdit("0");
    inputB->setStyleSheet(inputStyle);

    QLabel *lblC = new QLabel("c =");
    lblC->setStyleSheet(labelStyle);
    inputC = new QLineEdit("0");
    inputC->setStyleSheet(inputStyle);

    btnCalcular = new QPushButton("Calcular");
    btnCalcular->setStyleSheet(
        "QPushButton { background-color: #1a6ed8; color: white; font-size: 13px;"
        "font-weight: bold; padding: 6px 22px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #155bb5; }"
        "QPushButton:pressed { background-color: #0f4a96; }"
        );

    layoutEntrada->addStretch();
    layoutEntrada->addWidget(lblA);
    layoutEntrada->addWidget(inputA);
    layoutEntrada->addSpacing(15);
    layoutEntrada->addWidget(lblB);
    layoutEntrada->addWidget(inputB);
    layoutEntrada->addSpacing(15);
    layoutEntrada->addWidget(lblC);
    layoutEntrada->addWidget(inputC);
    layoutEntrada->addSpacing(25);
    layoutEntrada->addWidget(btnCalcular);
    layoutEntrada->addStretch();

    layoutPrincipal->addWidget(grupoEntrada);

    tabWidget = new QTabWidget();
    tabWidget->setStyleSheet(
        "QTabWidget::pane { border: 1.5px solid #4a90d9; border-radius: 4px; }"
        "QTabBar::tab { padding: 6px 16px; font-size: 11px; font-weight: bold; }"
        "QTabBar::tab:selected { background: #1a6ed8; color: white; border-radius: 3px; }"
        "QTabBar::tab:!selected { background: #e8eef7; color: #444; }"
        );

    tabWidget->addTab(crearPestaniaDiscriminante(), "Discriminante");
    tabWidget->addTab(crearPestaniaVertice(),       "Vértice y Corte Y");
    tabWidget->addTab(crearPestaniaTabla(),         "Tabla de valores");
    tabWidget->addTab(crearPestaniaGrafica(),       "Gráfica");

    layoutPrincipal->addWidget(tabWidget);

    connect(btnCalcular, &QPushButton::clicked, this, &MainWindow::onCalcular);
}

QWidget* MainWindow::crearPestaniaDiscriminante() {
    QWidget *w = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->setSpacing(12);
    layout->setContentsMargins(20, 20, 20, 20);

    QString resultStyle =
        "font-size: 13px; padding: 10px; background: #f0f5ff;"
        "border: 1px solid #c5d8f5; border-radius: 5px; color: #1a3a6e;";

    lblDiscriminante = new QLabel("Ingresa los coeficientes y presiona Calcular.");
    lblDiscriminante->setStyleSheet(resultStyle);
    lblDiscriminante->setWordWrap(true);
    lblDiscriminante->setMinimumHeight(80);

    lblRaices = new QLabel("Las raíces aparecerán aquí.");
    lblRaices->setStyleSheet(resultStyle);
    lblRaices->setWordWrap(true);
    lblRaices->setMinimumHeight(80);

    layout->addWidget(new QLabel("<b>Discriminante (Δ):</b>"));
    layout->addWidget(lblDiscriminante);
    layout->addWidget(new QLabel("<b>Raíces:</b>"));
    layout->addWidget(lblRaices);
    layout->addStretch();
    return w;
}

QWidget* MainWindow::crearPestaniaVertice() {
    QWidget *w = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->setSpacing(12);
    layout->setContentsMargins(20, 20, 20, 20);

    QString resultStyle =
        "font-size: 13px; padding: 10px; background: #f0f5ff;"
        "border: 1px solid #c5d8f5; border-radius: 5px; color: #1a3a6e;";

    lblVertice = new QLabel("El vértice aparecerá aquí.");
    lblVertice->setStyleSheet(resultStyle);
    lblVertice->setWordWrap(true);
    lblVertice->setMinimumHeight(70);

    lblCorteY = new QLabel("El corte en Y aparecerá aquí.");
    lblCorteY->setStyleSheet(resultStyle);
    lblCorteY->setWordWrap(true);
    lblCorteY->setMinimumHeight(70);

    layout->addWidget(new QLabel("<b>Vértice de la parábola:</b>"));
    layout->addWidget(lblVertice);
    layout->addWidget(new QLabel("<b>Corte con el eje Y:</b>"));
    layout->addWidget(lblCorteY);
    layout->addStretch();
    return w;
}

QWidget* MainWindow::crearPestaniaTabla() {
    QWidget *w = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->setContentsMargins(15, 15, 15, 15);

    tablaValores = new QTableWidget(11, 2);
    tablaValores->setHorizontalHeaderLabels({"x", "f(x)"});
    tablaValores->horizontalHeader()->setStretchLastSection(true);
    tablaValores->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tablaValores->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablaValores->setAlternatingRowColors(true);
    tablaValores->setStyleSheet(
        "font-size: 12px;"
        "QHeaderView::section { background-color: #1a6ed8; color: white; font-weight: bold; padding: 5px; }"
        );

    layout->addWidget(tablaValores);
    return w;
}

QWidget* MainWindow::crearPestaniaGrafica() {
    QWidget *w = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->setContentsMargins(10, 10, 10, 10);

    graficaWidget = new GraficaWidget();
    layout->addWidget(graficaWidget);

    QLabel *leyenda = new QLabel("● Azul: parábola    ● Rojo: vértice    ● Verde: raíces reales");
    leyenda->setAlignment(Qt::AlignCenter);
    leyenda->setStyleSheet("font-size: 10px; color: #555; margin-top: 4px;");
    layout->addWidget(leyenda);

    return w;
}

void MainWindow::onCalcular() {
    bool okA, okB, okC;
    float a = inputA->text().toFloat(&okA);
    float b = inputB->text().toFloat(&okB);
    float c = inputC->text().toFloat(&okC);

    if (!okA || !okB || !okC) {
        QMessageBox::warning(this, "Error de entrada",
                             "Por favor ingresa valores numéricos válidos en a, b y c.");
        return;
    }

    if (a == 0) {
        QMessageBox::warning(this, "Error en coeficiente a",
                             "El coeficiente 'a' no puede ser 0.\n"
                             "Si a = 0, la función deja de ser cuadrática.");
        inputA->setFocus();
        return;
    }

    Calculadora calc(a, b, c);

    ResultadoDiscriminante disc = calc.CalculoDiscriminante();
    QString textoDisc = QString("Δ = (%1)² - 4·(%2)·(%3) = %4")
                            .arg(b).arg(a).arg(c)
                            .arg(disc.discriminante, 0, 'f', 2);
    lblDiscriminante->setText(textoDisc + "\n\n" + QString::fromStdString(disc.mensaje));

    QString textoRaices;
    if (disc.cantidadRaices == 2) {
        textoRaices = QString("x₁ = %1\nx₂ = %2")
                          .arg(disc.x1, 0, 'f', 4)
                          .arg(disc.x2, 0, 'f', 4);
    } else if (disc.cantidadRaices == 1) {
        textoRaices = QString("x₁ = %1\n(La parábola es tangente al eje X)")
                          .arg(disc.x1, 0, 'f', 4);
    } else {
        textoRaices = "No existen raíces reales.\n(La parábola no toca el eje X)";
    }
    lblRaices->setText(textoRaices);

    ResultadoVertice vert = calc.CalculoVertice();
    lblVertice->setText(QString("Vértice = (%1 , %2)")
                            .arg(vert.vx, 0, 'f', 3)
                            .arg(vert.vy, 0, 'f', 3));

    float corteY = calc.CorteEjeY();
    lblCorteY->setText(QString("Corte en Y = (0 , %1)\n\nf(0) = c = %1")
                           .arg(corteY, 0, 'f', 2));

    llenarTabla(calc.ObtenerTabla());
    graficaWidget->setCoeficientes(a, b, c);
    tabWidget->setCurrentIndex(3);
}

void MainWindow::llenarTabla(const std::vector<std::pair<float,float>> &datos) {
    tablaValores->setRowCount((int)datos.size());
    for (int i = 0; i < (int)datos.size(); i++) {
        QTableWidgetItem *itemX  = new QTableWidgetItem(QString::number(datos[i].first, 'f', 0));
        QTableWidgetItem *itemFx = new QTableWidgetItem(QString::number(datos[i].second, 'f', 4));
        itemX->setTextAlignment(Qt::AlignCenter);
        itemFx->setTextAlignment(Qt::AlignCenter);
        tablaValores->setItem(i, 0, itemX);
        tablaValores->setItem(i, 1, itemFx);
    }
}
