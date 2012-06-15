#-------------------------------------------------
#
# Project created by QtCreator 2012-06-16T04:38:46
#
#-------------------------------------------------

QT       += core gui

TARGET = ASMIDE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qscilexerasm.cpp

HEADERS  += mainwindow.h \
    qscilexerasm.h

FORMS    += mainwindow.ui

unix: CONFIG += link_pkgconfig
unix: LIBS += -lqscintilla2
