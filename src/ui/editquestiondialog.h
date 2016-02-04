/******************************************************************************
 * editquestiondialog.h : dialog for editing quiz questions
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

#ifndef EDITQUESTIONDIALOG_H
#define EDITQUESTIONDIALOG_H

#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

namespace Ui {
    class EditQuestionDialog;
}

class EditQuestionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditQuestionDialog(QWidget *parent = 0);
    ~EditQuestionDialog();

    void setupFormLayout();
    void setupButtonBox();
    void setupMasterLayout();

    QStringList getChoices();
    QString getQuestion();
    QString getAnswer();
    int getPosition();
    int getPoints();


private slots:
    void addChoice();

private:
    Ui::EditQuestionDialog *ui;
    QFormLayout *formLayout;
    QVBoxLayout *masterLayout;
    QHBoxLayout *buttonBox;

    QLabel *questionLabel;
    QLabel *answerLabel;
    QLabel *positionLabel;
    QLabel *pointsLabel;

    QLineEdit *questionLineEdit;
    QLineEdit *answerLineEdit;
    QLineEdit *positionLineEdit;
    QLineEdit *pointsLineEdit;
    QLineEdit *choiceLineEdit;

    QPushButton *addChoiceButton;
    QPushButton *acceptButton;
    QPushButton *rejectButton;
};

#endif // EDITQUESTIONDIALOG_H
