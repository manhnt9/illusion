#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include "illusion/illusion.hpp"

int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    QApplication a(argc, argv);
//    QMainWindow w;
//    w.show();


//    il::Illusion::instance()->run();
    return a.exec();
}
