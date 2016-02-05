/******************************************************************************
 * questionlayout.h : a way to display quiz questions
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

#ifndef QUESTIONLAYOUT_H
#define QUESTIONLAYOUT_H

#include "multichoicequestion.h"
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QRadioButton>

// TODO: re-write to inherit from QLayout

namespace Ui {
class QuestionLayout;
}

class QuestionLayout : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionLayout(QWidget *parent = 0, MultiChoiceQuestion question = MultiChoiceQuestion());
    ~QuestionLayout();
    MultiChoiceQuestion getQuestion();

private:
    Ui::QuestionLayout *ui;
    MultiChoiceQuestion question;
    QFormLayout *formLayout;
    QLabel *numberLabel;
    QLabel *questionLabel;
    QLabel *answerLabel;
    QRadioButton *radioButton;

    void setupFormLayout();
};

#endif // QUESTIONLAYOUT_H
