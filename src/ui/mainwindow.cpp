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

    // Here for testing
    MultiChoiceQuestion que;
    que.setPosition(1);
    que.setPoints(1);
    que.setQuestion("This is a question");

    QStringList list;
    list.append("One");
    list.append("Two");
    list.append("Three");
    que.setChoices(list);
    que.setCorrectAnswer("This is the answer");

    form = new QuestionForm(0, que);
    form->setupFormLayout();

    button = new QPushButton("Hello");
    boxLayout = new QVBoxLayout;
    boxLayout->addWidget(button);
    boxLayout->addWidget(form);

    // /stuff for testing

    centralWidget()->setLayout(boxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
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
        edit_dialog.getChoices();
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
        error_message.showMessage("Error creating file.");
    }
}

void MainWindow::on_actionOpen_Quiz_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open File"), QDir::homePath(), tr("CSV Files (*.csv)"));
}
