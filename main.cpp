/*
    main.cpp
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

#include "mainwindow.h"
#include "database.h"
#include <string>
#include <QSplashScreen>
#include <QTimer>
#include <QMovie>
#include <QLabel>
#include <QApplication>
#include<QDesktopServices>

int main(int argc, char *argv[])
{

    database * dat = new database();

    QApplication a(argc, argv);


    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/resources/img/Heavid.png"));
    splash->show();

    MainWindow w;


    //QTimer::singleShot(3200, movie, SLOT(stop()));
    QTimer::singleShot(1000, splash, SLOT(close()));
    QTimer::singleShot(1000, &w, SLOT(show()));

    //w.show();


    delete dat;
    return a.exec();
}
