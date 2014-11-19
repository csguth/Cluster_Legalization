#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T12:55:13
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_cluster_legalizationtest
CONFIG   += console -Wall -Werror
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_cluster_legalizationtest.cpp \
    row.cpp \
    cluster.cpp \
    range_in_cluster.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    row.h \
    cluster.h \
    util.h \
    exception.h \
    range_in_cluster.h
