#include <QApplication>
#include "rosQT_gui/mainwindow.h"

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "my_qt_gui");
    QApplication app(argc, argv);

    ros::NodeHandle nh;
    MainWindow window(nh);
    window.show();

    return app.exec();
}