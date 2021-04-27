/*
    mainwindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <exercise_description.h>
#include <dialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void saveToFile();
    void loadFromFile();
    QString exerGenName;
    QString exerName;




private slots:

    void on_CoBegList_itemClicked(QListWidgetItem *item);
    void on_CoBegList_itemDoubleClicked(QListWidgetItem *item);

    void on_CoIntList_itemDoubleClicked(QListWidgetItem *item);
    void on_CoIntList_itemClicked(QListWidgetItem *item);

    void on_CoAdvList_itemDoubleClicked(QListWidgetItem *item);
    void on_CoAdvList_itemClicked(QListWidgetItem *item);

    void on_UppBodyBegList_itemDoubleClicked(QListWidgetItem *item);
    void on_UppBodyBegList_itemClicked(QListWidgetItem *item);

    void on_UppBodyIntList_itemDoubleClicked(QListWidgetItem *item);
    void on_UppBodyIntList_itemClicked(QListWidgetItem *item);

    void on_UppBodyAdvList_itemDoubleClicked(QListWidgetItem *item);
    void on_UppBodyAdvList_itemClicked(QListWidgetItem *item);

    void on_LoBodyBegList_itemClicked(QListWidgetItem *item);
    void on_LoBodyBegList_itemDoubleClicked(QListWidgetItem *item);

    void on_LoBodyIntList_itemClicked(QListWidgetItem *item);
    void on_LoBodyIntList_itemDoubleClicked(QListWidgetItem *item);

    void on_LoBodyAdvList_itemClicked(QListWidgetItem *item);
    void on_LoBodyAdvList_itemDoubleClicked(QListWidgetItem *item);

    //for generating images
    //void on_CoBegList_itemClicked(QListWidgetItem *item);

    //void on_CoreButton_clicked(bool checked);

    //void on_LowerBodyButton_clicked(bool checked);

    void on_loadButton_clicked();

    void on_saveButton_clicked();

    void on_clearButton_clicked();

    void on_showDescButton_clicked();

private:
    Ui::MainWindow *ui;
    Exercise_Description *exerdesc;

};
#endif // MAINWINDOW_H
