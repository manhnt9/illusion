#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T09:18:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = illusion
TEMPLATE = app
CONFIG   += c++11


SOURCES  += \
    main.cpp \
    illusion/iloperation.cpp \
    illusion/iltcpoperation.cpp \
    illusion/illusion.cpp

HEADERS  += \
    illusion/illusion.hpp \
    illusion/iloperation.hpp \
    illusion/iltcpoperation.hpp \
    illusion/illusion.ipp
