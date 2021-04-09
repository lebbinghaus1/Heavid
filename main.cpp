#include "mainwindow.h"
#include "database.h"
#include <string>

#include <QApplication>

int main(int argc, char *argv[])
{

    database * dat = new database();
    std::string queryStatement = dat -> createQueryStatement("Arms", "Beginner");
    sql::ResultSet * result = dat -> query(queryStatement);

    while (result -> next()) {
        std::cout << result -> getString(1) << std::endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    delete dat;

    return a.exec();
}
