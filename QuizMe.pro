QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuizMe
INCLUDEPATH += src
CONFIG += C++11
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/settings.cpp \
    src/logger.cpp \
    src/ui/questionlayout.cpp \
    src/quiz.cpp \
    src/ui/questioneditdialog.cpp

HEADERS  += \
    src/ui/mainwindow.h \
    src/settings.h \
    src/logger.h \
    src/ui/questionlayout.h \
    src/quiz.h \
    src/ui/questioneditdialog.h

FORMS    += \
    src/ui/mainwindow.ui \
    src/ui/editquestiondialog.ui \
    src/ui/questionlayout.ui \
    src/ui/questioneditdialog.ui
