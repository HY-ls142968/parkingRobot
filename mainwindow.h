#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rcslog.h"
#include "stdfx.h"
#include "macrodef.h"
#include "../sensors/motorctrl.h"
#include "../sensors/gyro.h"
#include "../sensors/pgvreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void PostLog(const char* msg_output, int flag);

private:
    Ui::MainWindow *ui;
    ThreadPool* tp;
    motorCtrl* ptrMotor;
    canBus* ptrCan;

    void init();
    int poweron_self_check();
    void hardFault_handle();
    void logInit();
    void canMsgHandle(QString);
    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
    void task7();

private slots:
    void showLog(const char* msg_output, int flag);
    void on_pushButton_clicked();

signals:
    void receiveHttpMsg(QString msg);
    void postlog(const char* msg_output, int flag);
};

#endif // MAINWINDOW_H
