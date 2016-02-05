/******************************************************************************
 * mainwindow.cpp : implementation for MainWindow class
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editquestiondialog.h"
#include "settings.h"
#include "logger.h"
#include "multichoicequestion.h"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QtDebug>

#define APPLICATION_VERSION "0.1"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QCoreApplication::setApplicationName("QuizMe");
    QCoreApplication::setOrganizationName("LeftySolara");
    QCoreApplication::setApplicationVersion(APPLICATION_VERSION);

    logger::setup();
    qInfo("Starting application...");

    if (!settings::settingsExist()) {
        qDebug("No configuration file found. Creating...");
        if (settings::createSettingsFile())
            qDebug("Successfully created configuration file.");
        else
            qDebug("Could not create configuration file.");
    }
    ui->setupUi(this);

    mainLayout = new QVBoxLayout;

    // Here for testing
//    MultiChoiceQuestion que;
//    que.setPosition(1);
//    que.setPoints(1);
//    que.setQuestion("This is a question");

//    QStringList list;
//    list.append("One");
//    list.append("Two");
//    list.append("Three");
//    que.setChoices(list);
//    que.setCorrectAnswer("This is the answer");

//    form = new QuestionLayout(0, que);
//    form->setupFormLayout();

//    button = new QPushButton("Hello");
//    boxLayout = new QVBoxLayout;
//    boxLayout->addWidget(button);
//    boxLayout->addWidget(form);

    // /stuff for testing

//    centralWidget()->setLayout(boxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainLayout;

    for (int i = 0; i < questionLayouts.size(); ++i)
        delete questionLayouts[i];
}

// Read a file and create question objects out of it
// Assumes the csv file is formatted as: question,answer,position,points,choice1,choice2,...,choiceN
void MainWindow::openQuizFromFile(QString filename)
{
    QFile targetFile(filename);
    if (!targetFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug("Could not open csv file.");
        return;
    }

    QuestionLayout *layout;

    QTextStream in(&targetFile);
    while (!in.atEnd()) {
        QStringList line = in.readLine().split(',');
        if (line.isEmpty())
            continue;

        MultiChoiceQuestion question;
        for (int i = 0; i < line.size(); ++i) {
            if (i == 0)
                question.setQuestion(line[i]);
            else if (i == 1)
                question.setCorrectAnswer(line[i]);
            else if (i == 2)
                question.setPosition(line[i].toInt());
            else if (i == 3)
                question.setPoints(line[i].toInt());
            else
                question.addChoice(line[i]);
        }
        layout = new QuestionLayout(0, question);
        questionLayouts.push_back(layout);
    }
    targetFile.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionNew_Question_triggered()
{
    EditQuestionDialog edit_dialog;

    int result = edit_dialog.exec();
    if (result == QDialog::Accepted) {
        MultiChoiceQuestion que;
        que.setQuestion(edit_dialog.getQuestion());
        que.setCorrectAnswer(edit_dialog.getAnswer());
        que.setPosition(edit_dialog.getPosition());
        que.setPoints(edit_dialog.getPoints());
        que.setChoices(edit_dialog.getChoices());

        QuestionLayout *newLayout = new QuestionLayout(0, que);

        questionLayouts.push_back(newLayout);
    }

}

void MainWindow::on_actionNewQuiz_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
        tr("New Quiz"), QDir::homePath(), tr("CSV Files (*.csv)"));

    if (filename.isEmpty())
        return;

    QFile new_file(filename);
    if (new_file.open(QIODevice::ReadWrite)) {
        qInfo("New quiz file created successfully.");
        new_file.close();
    }
    else {
        qCritical() << "Unable to create new quiz file " << filename << ".";
        errorMessage.showMessage("Error creating file.");
    }
}

void MainWindow::on_actionOpen_Quiz_triggered()
{
    // absolute path to file
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), QDir::homePath(), tr("CSV Files (*.csv)"));
    openQuizFromFile(filename);

    for (int i = 0; i < questionLayouts.size(); ++i) {
        mainLayout->addWidget(questionLayouts[i]);
    }
    centralWidget()->setLayout(mainLayout);
}
