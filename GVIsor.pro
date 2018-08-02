#-------------------------------------------------
#
# Project created by QtCreator 2017-10-18T16:26:10
#
#-------------------------------------------------

CONFIG += c++14
QT       += core \
            gui \
            sql \
            xlsx \
            printsupport \
            axcontainer \
            #webenginewidgets \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GVIsor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Ressources/chantier.cpp \
    Ressources/engine.cpp \
    global_functions.cpp \
    gvi_recap.cpp \
    export.cpp \
    print.cpp \
    parser.cpp \
    error.cpp \
    connectiondialog.cpp

HEADERS  += mainwindow.h \
    Ressources/chantier.h \
    Ressources/engine.h \
    global_functions.h \
    gvi_recap.h \
    export.h \
    print.h \
    parser.h \
    error.h \
    connectiondialog.h

FORMS    += mainwindow.ui \
    gvi_recap.ui \
    connectiondialog.ui

RC_FILE += myapp.rc

RESOURCES += \
    program.qrc

include(itemgvi.pri)
