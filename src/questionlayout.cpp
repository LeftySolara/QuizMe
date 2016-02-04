/******************************************************************************
 * questionlayout.cpp : a way to display quiz questions
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

#include "questionlayout.h"
#include "ui_questionlayout.h"

QuestionLayout::QuestionLayout(QWidget *parent, MultiChoiceQuestion question) :
    QWidget(parent),
    ui(new Ui::QuestionLayout)
{
    ui->setupUi(this);

    this->question = question;
    setupFormLayout();
}

QuestionLayout::~QuestionLayout()
{
    delete ui;
}

MultiChoiceQuestion QuestionLayout::getQuestion()
{
    return this->question;
}

void QuestionLayout::setupFormLayout()
{
    formLayout = new QFormLayout();

    questionLabel = new QLabel(question.getQuestion());
    numberLabel = new QLabel(QString::number(question.getPosition()) + ")");
    formLayout->addRow(numberLabel, questionLabel);

    // TODO: Make shuffling optional through settings menu
    question.shuffleChoices();
    for (int i = 0; i < question.choices.size(); ++i) {
        radioButton = new QRadioButton();
        answerLabel = new QLabel(question.choices[i]);
        formLayout->addRow(radioButton, answerLabel);
    }

    this->setLayout(formLayout);
}
