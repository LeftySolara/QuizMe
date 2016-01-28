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
    src/shortanswerquestion.cpp \
    src/questionform.cpp

HEADERS  += \
    src/ui/mainwindow.h \
    src/ui/editquestiondialog.h \
    src/settings.h \
    src/logger.h \
    src/quizquestion.h \
    src/multichoicequestion.h \
    src/shortanswerquestion.h \
    src/questionform.h

FORMS    += \
    src/ui/mainwindow.ui \
    src/ui/editquestiondialog.ui \
    src/questionform.ui
