#include "illusion/illusion.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <google/protobuf/message.h>

int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    QApplication a(argc, argv);
//    QMainWindow w;
//    w.show();


//    il::Illusion::instance()->run();
    return a.exec();
}
