#-------------------------------------------------
#
# Project created by QtCreator 2019-10-30T09:37:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ParkingRobotTh
TEMPLATE = app
CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    stdfx.cpp \
    rcslog.cpp \
    communicationBus/canbus.cpp \
    communicationBus/serialbus.cpp \
    communicationBus/ethernetbus.cpp \
    sensors/motorctrl.cpp \
    sensors/pgvreader.cpp \
    sensors/sicklaser.cpp \
    sensors/gyro.cpp \
    sensors/radar.cpp \
    sensors/joycontrol.cpp \
    timer.cpp

HEADERS += \
        mainwindow.h \
    stdfx.h \
    rcslog.h \
    communicationBus/canbus.h \
    communicationBus/serialbus.h \
    communicationBus/ethernetbus.h \
    sensors/motorctrl.h \
    sensors/pgvreader.h \
    sensors/sicklaser.h \
    sensors/gyro.h \
    sensors/radar.h \
    macrodef.h \
    sensors/joycontrol.h \
    timer.h

INCLUDEPATH += \
    $$PWD/external  \
    $$PWD/external/opencv/include \
    $$PWD/external/spdlog

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
