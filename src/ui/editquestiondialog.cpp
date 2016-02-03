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
#include <QtDebug>

EditQuestionDialog::EditQuestionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditQuestionDialog)
{
    ui->setupUi(this);

    setupFormLayout();
    setupButtonBox();
    setupMasterLayout();
}

EditQuestionDialog::~EditQuestionDialog()
{
    delete ui;
    delete formLayout;
    delete questionLabel;
    delete questionLineEdit;
    delete positionLabel;
    delete pointsLabel;
    delete answerLabel;
    delete answerLineEdit;
    delete choiceLineEdit;
    delete addChoiceButton;
    delete buttonBox;
    delete rejectButton;
    delete acceptButton;
    delete masterLayout;
}

void EditQuestionDialog::setupFormLayout()
{
    questionLabel = new QLabel("Question");
    answerLabel = new QLabel("Answer");
    positionLabel = new QLabel("Position");
    pointsLabel = new QLabel("Points");

    questionLineEdit = new QLineEdit();
    answerLineEdit = new QLineEdit();
    positionLineEdit = new QLineEdit();
    pointsLineEdit = new QLineEdit();
    choiceLineEdit = new QLineEdit();

    addChoiceButton = new QPushButton("Add choice");
    addChoiceButton->setFocusPolicy(Qt::ClickFocus);
    connect(addChoiceButton, SIGNAL (clicked()), this, SLOT (addChoice()));

    questionLineEdit->setPlaceholderText("Enter a question...");
    answerLineEdit->setPlaceholderText("Enter the correct answer...");
    positionLineEdit->setPlaceholderText("Enter position in quiz...");
    pointsLineEdit->setPlaceholderText("Enter number of points for this question...");
    choiceLineEdit->setPlaceholderText("Enter another answer choice...");

    formLayout = new QFormLayout();
    formLayout->addRow(positionLabel, positionLineEdit);
    formLayout->addRow(pointsLabel, pointsLineEdit);
    formLayout->addRow(questionLabel, questionLineEdit);
    formLayout->addRow(answerLabel, answerLineEdit);
    formLayout->addRow(addChoiceButton, choiceLineEdit);

    formLayout->setLabelAlignment(Qt::AlignRight);
    formLayout->setFormAlignment(Qt::AlignTop);
}

void EditQuestionDialog::setupButtonBox()
{
    buttonBox = new QHBoxLayout();
    acceptButton = new QPushButton("OK");
    rejectButton = new QPushButton("Cancel");

    connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(rejectButton, SIGNAL(clicked()), this, SLOT(reject()));

    buttonBox->addWidget(acceptButton);
    buttonBox->addWidget(rejectButton);
}

void EditQuestionDialog::setupMasterLayout()
{
    masterLayout = new QVBoxLayout();
    masterLayout->addLayout(formLayout);
    masterLayout->addLayout(buttonBox);
    masterLayout->setAlignment(formLayout, Qt::AlignTop);
    masterLayout->setAlignment(buttonBox, Qt::AlignBottom);
    this->setLayout(masterLayout);
}

// Check each line edit for input and add it to a stringlist
QStringList EditQuestionDialog::getChoices()
{
    QStringList choices;
    int row_count = formLayout->rowCount();

    for (int row = 2; row < row_count; ++row) {    // first two rows are the question and correct answer
        choiceLineEdit = (QLineEdit*)formLayout->itemAt(row, QFormLayout::FieldRole)->widget();
        if (!choiceLineEdit->text().isEmpty())
            choices.append(choiceLineEdit->text());
    }
    return choices;
}

void EditQuestionDialog::addChoice()
{
    QLabel *blankLabel = new QLabel();   // use to keep formLayout aligned
    choiceLineEdit = new QLineEdit();
    choiceLineEdit->setPlaceholderText("Enter another answer choice...");
    formLayout->addRow(blankLabel, choiceLineEdit);

    this->setTabOrder(choiceLineEdit, acceptButton);
    this->setTabOrder(acceptButton, rejectButton);
    this->setLayout(masterLayout);
}
