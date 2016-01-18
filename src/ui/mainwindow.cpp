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

#define APPLICATION_VERSION "0.1"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QCoreApplication::setApplicationName("QuizMe");
    QCoreApplication::setOrganizationName("QuizMe");
    QCoreApplication::setApplicationVersion(APPLICATION_VERSION);

    if (!settings::settingsExist()) {
        qDebug("Creating settings file...");
        if (settings::createSettingsFile())
            qDebug("Successfully created settings file.");
        else
            qDebug("Could not create settings file.");
    }
    ui->setupUi(this);
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
    if (result == QDialog::Accepted)
        qDebug("Accepted");
    else if (result == QDialog::Rejected)
        qDebug("Rejected");
}
