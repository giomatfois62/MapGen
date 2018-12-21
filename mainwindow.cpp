#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>

#include "matrix.h"
#include "openglwindow.h"
#include "mapgenerator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_window = new OpenGLWindow;

    QWidget *container = QWidget::createWindowContainer(m_window, this);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(container);
    ui->container->setLayout(layout);

    int startingSeed = rand()%999999999;
    ui->seed->setValue(startingSeed);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_window;
}

void MainWindow::on_generate_clicked()
{
    int seed = ui->seed->value();
    int size = ui->size->value();

    MapGenerator generator;
    Matrix<float> A = generator.generate(size, seed);

    Surface surf(A);
    m_window->setSurface(surf);
}

void MainWindow::on_randomize_clicked()
{
    int seed =  QDateTime::currentSecsSinceEpoch();
    int size = ui->size->value();

    MapGenerator generator;
    Matrix<float> A = generator.generate(size, seed);

    Surface surf(A);
    m_window->setSurface(surf);
}
