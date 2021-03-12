#include "mainwindow.h"
#include "ui_mainwindow.h"

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


/*void MainWindow::on_UpperBodyButton1_clicked(bool checked)
{
    ui->listWidget->addItem("push ups");

}*/

/*void MainWindow::on_UpperBodyButton1_pressed()
{
    ui->listWidget->addItem("push ups");
}*/
