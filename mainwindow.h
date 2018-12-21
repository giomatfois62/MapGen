#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "openglwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generate_clicked();

    void on_randomize_clicked();

private:
    Ui::MainWindow *ui;

    OpenGLWindow *m_window;
};

#endif // MAINWINDOW_H
