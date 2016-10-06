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

LIBS                += -lglog -lprotobuf-lite

INCLUDEPATH         += message

PROTOS              =  message/checkaccount.proto

include(protobuf.pri)

CONFIG(private) {
    SOURCES         += vt/vthttpoperation.cpp
    HEADERS         += vt/vthttpoperation.hpp \
                        vt/vthttpoperation.ipp

    PROTOS          += vt/proto/comm.account.proto \
                        vt/proto/comm.chat.proto \
                        vt/proto/comm.message.proto \
                        vt/proto/comm.profile.proto \
                        vt/proto/comm.call.proto \
                        vt/proto/comm.contact.proto \
                        vt/proto/comm.model.proto \
                        vt/proto/store.proto
}

SOURCES             += main.cpp \
                        illusion/iloperation.cpp \
                        illusion/iltcpoperation.cpp \
                        illusion/illusion.cpp \
                        illusion/ilmanager.cpp

HEADERS             += illusion/illusion.hpp \
                        illusion/illusion.ipp \
                        illusion/iloperation.hpp \
                        illusion/iloperation.ipp \
                        illusion/iltcpoperation.hpp \
                        illusion/iltcpoperation.ipp \
                        illusion/ilstate.hpp \
                        illusion/iltype.hpp \
                        illusion/ilmanager.hpp \
                        illusion/ilmanager.ipp

DISTFILES           += message/checkaccount.proto
