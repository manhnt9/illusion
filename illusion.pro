#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T09:18:47
#
#-------------------------------------------------

QT                  += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET              = illusion
TEMPLATE            = app
CONFIG              += c++11

LIBS                += -lglog -lprotobuf

INCLUDEPATH         += message

PROTOS              =  message/message.proto

include(protobuf.pri)

SOURCES             += main.cpp \
                        illusion/iloperation.cpp \
                        illusion/iltcpoperation.cpp \
                        illusion/illusion.cpp \
                        illusion/ilmanager.cpp \
                        message/ilmessage.cpp \
                        benchmark/ilbenchmark.cpp \
                        benchmark/ildelayedoperation.cpp \
                        benchmark/ilconnectionbenchmark.cpp \
                        illusion/ilhttpoperation.cpp \
                        illusion/ilhttpmanager.cpp

HEADERS             += illusion/illusion.hpp \
                        illusion/illusion.ipp \
                        illusion/iloperation.hpp \
                        illusion/iloperation.ipp \
                        illusion/iltcpoperation.hpp \
                        illusion/iltcpoperation.ipp \
                        illusion/ilstate.hpp \
                        illusion/ilmanager.hpp \
                        illusion/ilmanager.ipp \
                        message/ilmessage.hpp \
                        benchmark/ilbenchmark.ipp \
                        benchmark/ilbenchmark.hpp \
                        benchmark/ildelayedoperation.hpp \
                        benchmark/ilconnectionbenchmark.hpp \
                        illusion/ilprint.hpp \
                        illusion/ilhttpoperation.hpp \
                        illusion/ilhttpmanager.hpp \
                        illusion/ilhttpmanager.ipp

DISTFILES           += message/message.proto
