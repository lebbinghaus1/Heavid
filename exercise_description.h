#ifndef EXERCISE_DESCRIPTION_H
#define EXERCISE_DESCRIPTION_H

#include <QDialog>
#include <QString>

namespace Ui {
class Exercise_Description;
}

class Exercise_Description : public QDialog
{
    Q_OBJECT

public:
    explicit Exercise_Description(QWidget *parent = nullptr, QString exerGenName=nullptr, QString exerName=nullptr);
    ~Exercise_Description();



private:
    Ui::Exercise_Description *ui;
};

#endif // EXERCISE_DESCRIPTION_H
