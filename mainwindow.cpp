/*
    mainwindow.cpp
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
#include "ui_mainwindow.h"
#include "database.h"
#include <vector>
#include <string>
#include <QSplashScreen>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <fstream>
#include <QVector>
#include <exercise_description.h>
#include <dialog.h>

using namespace std;

QString workoutExercise;
QVector <QString> workoutPlan;

database * dat = new database();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    //Query calls for Upper Body
    std::string queryStatement = dat -> createQueryStatement("Upper Body","Beginner");
    sql::ResultSet *result = dat -> query(queryStatement);
    QString exercisesPre,exercisesPost;
    while (result -> next()) {

        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->UppBodyBegList->addItem(exercisesPost);
    }

    queryStatement = dat -> createQueryStatement("Upper Body","Intermediate");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->UppBodyIntList->addItem(exercisesPost);
    }

    queryStatement = dat -> createQueryStatement("Upper Body","Advanced");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->UppBodyAdvList->addItem(exercisesPost);
    }

    //Query Calls for Lower Body
    queryStatement = dat -> createQueryStatement("Lower Body","Beginner");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->LoBodyBegList->addItem(exercisesPost);
    }

    queryStatement = dat -> createQueryStatement("Lower Body","Intermediate");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->LoBodyIntList->addItem(exercisesPost);
    }

    queryStatement = dat -> createQueryStatement("Lower Body","Advanced");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->LoBodyAdvList->addItem(exercisesPost);
    }

    //Query Calls for Core
    queryStatement = dat -> createQueryStatement("Core","Beginner");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->CoBegList->addItem(exercisesPost);
    }

    queryStatement = dat -> createQueryStatement("Core","Intermediate");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->CoIntList->addItem(exercisesPost);
    }

    queryStatement = dat -> createQueryStatement("Core","Advanced");
    result = dat -> query(queryStatement);
    while (result -> next()) {
        //resultString.push_back(result -> getString(1));
        //resultString.push_back(exercisesPre.fromStdString(result->getString(1)));
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        ui->CoAdvList->addItem(exercisesPost);
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}


//Code for displaying new window for exercise descriptions and images

//For Core Exercises
void MainWindow::on_CoBegList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}

void MainWindow::on_CoIntList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}

void MainWindow::on_CoAdvList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}


//For Upper Body Exercises
void MainWindow::on_UppBodyBegList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}

void MainWindow::on_UppBodyIntList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}

void MainWindow::on_UppBodyAdvList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}


//For Lower Body Exercises
void MainWindow::on_LoBodyBegList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}

void MainWindow::on_LoBodyIntList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}

void MainWindow::on_LoBodyAdvList_itemClicked(QListWidgetItem *item)
{
    std::string exerciseName;
    QString exerciseDesc,exercisesPre,exercisesPost;
    exerciseDesc=item->text();
    exerName=exerciseDesc;
    exerciseName=exerciseDesc.toStdString();

    std::string queryStatement = dat -> createDescQueryStatement(exerciseName);
    sql::ResultSet *result = dat -> query(queryStatement);

    while (result -> next()) {
        exercisesPost=exercisesPre.fromStdString(result->getString(1));
        exerGenName=exercisesPost;
    }
}



// Code for inserting desired exercises into workout list

//When Core Exercises are clicked
void MainWindow::on_CoBegList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");

}

void MainWindow::on_CoIntList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");

}

void MainWindow::on_CoAdvList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}


//When Upper Body Exercises are clicked
void MainWindow::on_UppBodyBegList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}

void MainWindow::on_UppBodyIntList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}

void MainWindow::on_UppBodyAdvList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}


//When Lower Body Exercises are clicked
void MainWindow::on_LoBodyBegList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}

void MainWindow::on_LoBodyIntList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}

void MainWindow::on_LoBodyAdvList_itemDoubleClicked(QListWidgetItem *item)
{
    workoutExercise = item->text();
    ui->workoutPlanList->addItem(workoutExercise);
    workoutPlan.push_back(workoutExercise+"\n");
}





void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Address Book"), "",
            tr("Address Book (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }


        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            line.replace(QString('$'), QString(" "));
            line.replace(QString('&'), QString(" "));
            ui->workoutPlanList->addItem(line);
        }



}
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Workout List"), "",
        tr("Workout List;All Files (*)"));
    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;

            }
            else{
                QTextStream out(&file);
                for (int i = 0; i < workoutPlan.size(); i++) {
                    out << workoutPlan[i];
                }

            }
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->workoutPlanList->clear();
    workoutPlan.clear();
}

void MainWindow::on_showDescButton_clicked()
{
    //Exercise_Description ExerciseDesc(nullptr,exerGenName);
    //ExerciseDesc.setModal(true);
    //ExerciseDesc.exec();

    exerdesc = new Exercise_Description(this,exerGenName,exerName);
    exerdesc->show();
}
