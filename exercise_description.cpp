#include "exercise_description.h"
#include "ui_exercise_description.h"
#include "mainwindow.h"
#include <iostream>
#include <string>
using namespace std;

Exercise_Description::Exercise_Description(QWidget *parent, QString exerGenName, QString exerName) :
    QDialog(parent),
    ui(new Ui::Exercise_Description)
{
    ui->setupUi(this);   
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);

    ui->textTitle->setText("  Exercise Description:\n");
    ui->textBrowser->insertPlainText(exerGenName);
    ui->textBrowser->setAlignment(Qt::AlignLeft);
    ui->exerciseImage->setStyleSheet("border-image:url(:/resources/img/"+ exerName+".png)");
}



Exercise_Description::~Exercise_Description()
{
    delete ui;
}
