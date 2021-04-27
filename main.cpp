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
