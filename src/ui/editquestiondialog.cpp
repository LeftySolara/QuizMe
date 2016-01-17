/******************************************************************************
 * editquestiondialog.cpp : dialog for editing quiz questions
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

#include "editquestiondialog.h"
#include "ui_editquestiondialog.h"

EditQuestionDialog::EditQuestionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditQuestionDialog)
{
    ui->setupUi(this);

    setup_formLayout();
    setup_buttonBox();
    setup_masterLayout();
}

EditQuestionDialog::~EditQuestionDialog()
{
    delete ui;
    delete formLayout;
    delete questionLabel;
    delete questionLineEdit;
    delete answerLabel;
    delete answerLineEdit;
    delete choiceLineEdit;
    delete addChoiceButton;
    delete buttonBox;
    delete rejectButton;
    delete acceptButton;
    delete masterLayout;
}

void EditQuestionDialog::setup_formLayout()
{
    questionLabel = new QLabel("Question");
    answerLabel = new QLabel("Answer");

    questionLineEdit = new QLineEdit();
    answerLineEdit = new QLineEdit();
    choiceLineEdit = new QLineEdit();

    addChoiceButton = new QPushButton("Add choice");
    connect(addChoiceButton, SIGNAL (clicked()), this, SLOT (on_addChoiceButton_Clicked()));

    questionLineEdit->setPlaceholderText("Enter a question...");
    answerLineEdit->setPlaceholderText("Enter the correct answer...");
    choiceLineEdit->setPlaceholderText("Enter another answer choice...");

    formLayout = new QFormLayout();
    formLayout->addRow(questionLabel, questionLineEdit);
    formLayout->addRow(answerLabel, answerLineEdit);
    formLayout->addRow(addChoiceButton, choiceLineEdit);

    formLayout->setLabelAlignment(Qt::AlignRight);
    formLayout->setFormAlignment(Qt::AlignTop);
}

void EditQuestionDialog::setup_buttonBox()
{
    buttonBox = new QHBoxLayout();
    acceptButton = new QPushButton("OK");
    rejectButton = new QPushButton("Cancel");

    connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(reject()));

    buttonBox->addWidget(acceptButton);
    buttonBox->addWidget(rejectButton);
}

void EditQuestionDialog::setup_masterLayout()
{
    masterLayout = new QVBoxLayout();
    masterLayout->addLayout(formLayout);
    masterLayout->addLayout(buttonBox);
    masterLayout->setAlignment(formLayout, Qt::AlignTop);
    masterLayout->setAlignment(buttonBox, Qt::AlignBottom);
    this->setLayout(masterLayout);
}

void EditQuestionDialog::on_addChoiceButton_Clicked()
{
    QLabel *blankLabel = new QLabel();   // use to keep formLayout aligned
    QLineEdit *newChoiceLineEdit = new QLineEdit();
    newChoiceLineEdit->setPlaceholderText("Enter another answer choice...");

    formLayout->addRow(blankLabel, newChoiceLineEdit);
    this->setLayout(masterLayout);
}
