#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QColorDialog>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>

#define DEFAULT_SIZE 5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mImage = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    mSize = DEFAULT_SIZE;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPainter;
    delete mImage;

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(mImage->rect(),Qt::white);
    painter.drawImage(0,0,*mImage);
    e->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    mEnabled = true;
    mBegin = e->pos();
    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(!mEnabled){
        e->accept();
        return;
    }
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);

    mEnd = e->pos();
    mPainter->setPen(pen);
    mPainter->drawLine(mBegin,mEnd);
    mBegin = mEnd;
    update();
    e->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    mEnabled = false;
    e->accept();
}


void MainWindow::on_actionTama_o_triggered()
{
    mSize = QInputDialog::getInt(this,"Tamaño de lápiz","Ingrese Tamaño: ",5,1);
}

void MainWindow::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black,this,"Color de lápiz");
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}
