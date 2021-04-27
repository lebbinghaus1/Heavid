/*
    exercise_description.cpp
    Part of Heavid
    Copyright (C) 2021  Misheel Bayarsaikhan, Keziah Charis Bulseco, Luke Ebbinghaus, Vanessa Garcia

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
