#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
// This is a test
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_UpperBodyButton1_clicked(bool checked);

    //void on_UpperBodyButton1_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
