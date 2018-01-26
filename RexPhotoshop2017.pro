#-------------------------------------------------
#
# Project created by QtCreator 2017-11-26T21:04:25
#
#-------------------------------------------------

QT       += core gui svg xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RexPhotoshop2017
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    graphicsviewclass.cpp \
    sceneclass.cpp \
    svgopen.cpp \
    askforsave.cpp \
    recttool.cpp \
    elltool.cpp \
    roundrecttool.cpp \
    commonwidget.cpp \
    item.cpp \
    selectiontool.cpp \
    polylinetool.cpp \
    tool.cpp \
    itembaseclass.cpp \
    itemrect.cpp \
    penwidget.cpp \
    brushwidget.cpp \
    roundcornerswidget.cpp \
    toolregistrator.cpp \
    itemell.cpp \
    itemroundrect.cpp

HEADERS += \
        mainwindow.h \
    graphicsviewclass.h \
    sceneclass.h \
    svgopen.h \
    askforsave.h \
    recttool.h \
    elltool.h \
    roundrecttool.h \
    commonwidget.h \
    item.h \
    selectiontool.h \
    polylinetool.h \
    tool.h \
    itembaseclass.h \
    itemrect.h \
    penwidget.h \
    brushwidget.h \
    roundcornerswidget.h \
    toolregistrator.h \
    itemell.h \
    itemroundrect.h

FORMS += \
        mainwindow.ui \
    askforsave.ui

DISTFILES +=
