/******************************************************************************
 * mainwindow.h : main window for application
 * ****************************************************************************
 * Copyright (C) 2016 Jalen Adams
 *
 * Authors: Jalen Adams <leftysolara@gmail.com>
 *
 * This file is part of QuizMe.
 *
 * QuizMe is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QuizMe is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QuizMe.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include "questionlayout.h"

// TODO: Write function that writes questions to a file

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupWelcomeScreen();
    void openQuizFromFile(QString filename);


private slots:
    void on_actionExit_triggered();
    void on_actionAbout_Qt_triggered();
    void on_actionNew_Question_triggered();
    void on_actionNewQuiz_triggered();
    void on_actionOpen_Quiz_triggered();

private:
    Ui::MainWindow *ui;
    QErrorMessage errorMessage;
    // QVector<QuestionLayout*> questionLayouts;
    QVBoxLayout *mainLayout;
    QVBoxLayout *welcomeScreenLayout;

    QPushButton *createQuizButton;
    QPushButton *editQuizButton;
    QPushButton *openQuizButton;

//    QVBoxLayout *boxLayout;
//    QPushButton *button;
//    QuestionLayout *form;
};

#endif // MAINWINDOW_H
