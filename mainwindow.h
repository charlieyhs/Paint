#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QPainter;
class QImage;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *e)override;
    void mousePressEvent(QMouseEvent *e)override;
    void mouseMoveEvent(QMouseEvent *e)override;
    void mouseReleaseEvent(QMouseEvent *e)override;
private slots:
    void on_actionTama_o_triggered();
    void on_actionColor_triggered();
    void on_actionSalir_triggered();

private:
    Ui::MainWindow *ui;
    QPainter *mPainter;// Pintor
    QImage *mImage;// imagen
    QPoint mBegin;// Comienzo
    QPoint mEnd;// Final
    QColor mColor;// Color
    bool mEnabled;// Activado
    int mSize;// Tamaño

};
#endif // MAINWINDOW_H
