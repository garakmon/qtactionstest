#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QtWidgets>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPixmap>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MainWindow::doStuff()
{
    QString docspath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString infilepath = QFileDialog::getOpenFileName(this, "Import Image", docspath, "Image Files (*.png *.bmp *.jpg *.dib *.JPG)");

    QPixmap pixmap =  QPixmap(infilepath);

    QGraphicsScene *scene = new QGraphicsScene;
    scene->addPixmap(pixmap);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_actionOpen_triggered()
{
    doStuff();
}

