/*
    exercise_description.h
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
