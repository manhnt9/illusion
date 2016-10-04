#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T09:18:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = illusion
TEMPLATE = app
CONFIG   += c++11

INCLUDEPATH += proto3/include
LIBS += -lglog $$PWD/proto3/lib/libprotobuf-lite.a

PROTOS = ./proto/test.proto
include(protobuf.pri)

SOURCES  += \
    main.cpp \
    illusion/iloperation.cpp \
    illusion/iltcpoperation.cpp \
    illusion/illusion.cpp \
    illusion/ilfactory.cpp \
    illusion/ilmanager.cpp \
    vt/vthttpoperation.cpp

HEADERS  += \
    illusion/illusion.hpp \
    illusion/illusion.ipp \
    illusion/iloperation.hpp \
    illusion/iloperation.ipp \
    illusion/iltcpoperation.hpp \
    illusion/iltcpoperation.ipp \
    illusion/ilstate.hpp \
    illusion/iltype.hpp \
    illusion/ilfactory.ipp \
    illusion/ilfactory.hpp \
    illusion/ilmanager.hpp \
    illusion/ilmanager.ipp \
    vt/vthttpoperation.hpp \
    vt/vthttpoperation.ipp

DISTFILES += \
    protobuf.pri
