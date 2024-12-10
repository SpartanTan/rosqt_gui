#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ros/ros.h>
#include <std_msgs/String.h>

namespace Ui{
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
     MainWindow(ros::NodeHandle &nh, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButton1Clicked();
    void onButton2Clicked();

private:
    Ui::MainWindow* ui;
    ros::NodeHandle n;
    ros::Publisher pub1;
    ros::Publisher pub2;
};

#endif // MAINWINDOW_H
