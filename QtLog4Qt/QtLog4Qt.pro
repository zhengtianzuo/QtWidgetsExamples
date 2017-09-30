#-------------------------------------------------
#
# Copyright (C) 2003-2103 CamelSoft Corporation
#
#-------------------------------------------------

QT       += core gui widgets

SOURCES += main.cpp\
        QtLog4Qt.cpp

HEADERS  += QtLog4Qt.h

FORMS    += QtLog4Qt.ui

include(log4qt/log4qt.pri)
INCLUDEPATH += log4qt
