#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chrt = new QChart;
    chrt->legend()->hide();

    ui->vchrt->setChart(chrt);
    chrt->setTitle("график");

    QValueAxis *axisX = new QValueAxis;
        axisX->setRange(0, 2.5);
        axisX->setTickCount(9);
        axisX->setLabelFormat("%.2f");
    QValueAxis *axisY = new QValueAxis;
        axisY->setRange(0, 4);
        axisY->setTickCount(12);
        axisY->setLabelFormat("%.2f");
    QLineSeries *series1 = new QLineSeries();

         for(double i = 0.1; i<2.5; i+=0.1)
         {
            series1->append(i, (2*i-log(i)));
         }

         chrt->addSeries(series1);
         chrt->setAxisX(axisX, series1);
         chrt->setAxisY(axisY, series1);
}

double function(double x) {
return 2*x - log(x);
}

void MainWindow::on_pushButton_clicked()
{
QString a1 = ui->lineEdit->text();
double a;
a=a1.toDouble();
QString b1 = ui->lineEdit_2->text();
double b;
b=b1.toDouble();
QString e1 = ui->lineEdit_3->text();
double e;
e=e1.toDouble();
double x1;
double x2;
x1 = a + (1 - 0.618) * (b - a);
x2 = a + 0.618 * (b - a);
double xf1;
double xf2;
xf1 = function(x1);
xf2 = function(x2);
P:
if(xf1 >= xf2)
{
a = x1;
x1 = x2;
xf1 = function(x2);
x2 = a + 0.618 * (b - a);
xf2 = function(x2);
}
else
{
b = x2;
x2 = x1;
xf2 = xf1;
x1 = a + (1 - 0.618) * (b - a);
xf1 = function(x1);
}
if(fabs(b - a) < e)
{
QString c1;
c1=QString::number(x1);
a1 = c1;
double d = function(x1);
QString d1;
d1=QString::number(d);
b1 = d1;
ui->label_3->setText(a1 + " " + b1);
}
else
goto P;
}

MainWindow::~MainWindow()
{
    delete ui;
}

