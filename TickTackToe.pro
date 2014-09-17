#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T02:52:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TickTackToe
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    board.cpp \
    space.cpp

HEADERS  += window.h \
    board.h \
    space.h

FORMS    += window.ui
