#-------------------------------------------------
#
# Project created by QtCreator 2010-09-19T08:14:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Indexing
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    cforwardindex.cpp \
    cinvertedindex.cpp \
    globalData.cpp

HEADERS += \
    cforwardindex.h \
    cinvertedindex.h \
    globalData.h
