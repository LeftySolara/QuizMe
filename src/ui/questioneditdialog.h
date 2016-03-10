/******************************************************************************
 * questioneditdialog.h : dialog for the user to edit questions
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

#ifndef QUESTIONEDITDIALOG_H
#define QUESTIONEDITDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>

namespace Ui {
class QuestionEditDialog;
}

class QuestionEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionEditDialog(int numChoices, QWidget *parent = 0);
    ~QuestionEditDialog();

    void setupLayoutMaster();
    void setupLayoutButtons();
    void setupLayoutForm();

    int position();
    int points();
    QString question();
    QString answer();
    QStringList choices();

private:
    Ui::QuestionEditDialog *ui;

    QVBoxLayout *layoutMaster;
    QHBoxLayout *layoutButtons;
    QFormLayout *layoutForm;

    QPushButton *buttonAccept;
    QPushButton *buttonReject;

    QSpinBox *spinboxPosition;
    QSpinBox *spinboxPoints;

    QLineEdit *lineEditQuestion;
    QLineEdit *lineEditAnswer;
    QLineEdit *lineEditChoice;

    const int numChoices;
};

#endif // QUESTIONEDITDIALOG_H
