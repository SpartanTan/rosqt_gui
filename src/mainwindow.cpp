#include "rosQT_gui/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ros::NodeHandle &nh, QWidget *parent) 
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), n(nh) {
    ui->setupUi(this);
    setWindowTitle("Qt Test Window");

    pub1 = n.advertise<std_msgs::String>("button1_topic", 10);
    pub2 = n.advertise<std_msgs::String>("button2_topic", 10);

    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onButton1Clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::onButton2Clicked);
    // resize(400, 300);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onButton1Clicked() {
    std_msgs::String msg;
    msg.data = "Button 1 Pressed!";
    pub1.publish(msg);
    ROS_INFO("Published: %s", msg.data.c_str());
}

void MainWindow::onButton2Clicked() {
    std_msgs::String msg;
    msg.data = "Button 2 Pressed!";
    pub2.publish(msg);
    ROS_INFO("Published: %s", msg.data.c_str());
}