QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuizMe
INCLUDEPATH += src
CONFIG += C++11
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/question.cpp \
    src/ui/editquestiondialog.cpp

HEADERS  += \
    src/ui/mainwindow.h \
    src/question.h \
    src/ui/editquestiondialog.h

FORMS    += \
    src/ui/mainwindow.ui \
    src/ui/editquestiondialog.ui
