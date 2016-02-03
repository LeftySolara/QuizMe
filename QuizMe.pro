QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuizMe
INCLUDEPATH += src
CONFIG += C++11
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/editquestiondialog.cpp \
    src/settings.cpp \
    src/logger.cpp \
    src/quizquestion.cpp \
    src/multichoicequestion.cpp \
    src/questionlayout.cpp \
    src/quiz.cpp

HEADERS  += \
    src/ui/mainwindow.h \
    src/ui/editquestiondialog.h \
    src/settings.h \
    src/logger.h \
    src/quizquestion.h \
    src/multichoicequestion.h \
    src/questionlayout.h \
    src/quiz.h

FORMS    += \
    src/ui/mainwindow.ui \
    src/ui/editquestiondialog.ui \
    src/questionlayout.ui
