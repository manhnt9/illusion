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

CONFIG(private) {
    SOURCES         += vt/vtmessage.cpp \
                        vt/vthttpoperation.cpp \
                        vt/vtpostoperation.cpp \
                        vt/vttcpoperation.cpp \
                        vt/vtbenchmark.cpp

    HEADERS         += vt/vthttpoperation.hpp \
                        vt/vthttpoperation.ipp \
                        vt/vtpostoperation.hpp \
                        vt/vttcpoperation.hpp \
                        vt/vttcpoperation.ipp \
                        vt/vtserver.hpp

    PROTOS          += vt/proto/comm.account.proto \
                        vt/proto/comm.call.proto \
                        vt/proto/comm.chat.proto \
                        vt/proto/comm.message.proto \
                        vt/proto/comm.profile.proto \
                        vt/proto/comm.contact.proto \
                        vt/proto/comm.model.proto \
                        vt/proto/store.proto
}

SOURCES             += main.cpp \
                        illusion/iloperation.cpp \
                        illusion/iltcpoperation.cpp \
                        illusion/illusion.cpp \
                        illusion/ilmanager.cpp \
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
