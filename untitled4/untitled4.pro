#-------------------------------------------------
#
# Project created by QtCreator 2017-10-10T21:55:22
#
#-------------------------------------------------

QT       += core gui printsupport xml
QT += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled4
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
    opencvwoker.cpp

HEADERS += \
        mainwindow.h \
    opencvwoker.h

FORMS += \
        mainwindow.ui
INCLUDEPATH += C:\opencv_src\Mingw_build\install\include\

LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_core340.dll
LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_highgui340.dll
LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_imgcodecs340.dll
LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_imgproc340.dll
LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_features2d340.dll
LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_calib3d340.dll
LIBS += C:\opencv_src\Mingw_build\install\x86\mingw\bin\libopencv_videoio340.dll
