#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T15:50:58
#
#-------------------------------------------------

QT       -= gui

TARGET = RSLSequences
TEMPLATE = lib

DEFINES += RSLSEQUENCES_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ibuildersetpoints.cpp \
    builderlinepoints.cpp

HEADERS += \
    IPermutation.h \
    PermutationShift.h \
    IBuilderSetPoints.h \
    BuilderLinePoints.h
    rslsequences_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Core/build-RSLCore-Desktop_Qt_5_7_1_MinGW_32bit-Release/release/ -lRSLCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Core/build-RSLCore-Desktop_Qt_5_7_1_MinGW_32bit-Release/debug/ -lRSLCore
else:unix: LIBS += -L$$PWD/../../Core/build-RSLCore-Desktop_Qt_5_7_1_MinGW_32bit-Release/ -lRSLCore

INCLUDEPATH += $$PWD/../../Core/RSLCore
DEPENDPATH += $$PWD/../../Core/RSLCore
