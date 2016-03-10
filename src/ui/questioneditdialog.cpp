/******************************************************************************
 * questioneditdialog.cpp : dialog for the user to edit questions
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

#include "questioneditdialog.h"
#include "ui_questioneditdialog.h"

QuestionEditDialog::QuestionEditDialog(int numChoices, QWidget *parent) :
    QDialog(parent), ui(new Ui::QuestionEditDialog), numChoices(numChoices)
{
    ui->setupUi(this);

    setupLayoutButtons();
    setupLayoutForm();
    setupLayoutMaster();

    setLayout(layoutMaster);
}

QuestionEditDialog::~QuestionEditDialog()
{
    delete ui;

    delete layoutForm;
    delete layoutButtons;
    delete layoutMaster;
}

void QuestionEditDialog::setupLayoutMaster()
{
    layoutMaster = new QVBoxLayout;
    layoutMaster->addLayout(layoutForm);
    layoutMaster->addLayout(layoutButtons);
}

// Set up the layout containing the "accept" and "reject" buttons
void QuestionEditDialog::setupLayoutButtons()
{
    layoutButtons = new QHBoxLayout;
    buttonAccept = new QPushButton("Accept");
    buttonReject = new QPushButton("Cancel");

    connect(buttonAccept, SIGNAL(clicked()), this, SLOT(accept()));
    connect(buttonReject, SIGNAL(clicked()), this, SLOT(reject()));

    layoutButtons->addWidget(buttonAccept);
    layoutButtons->addWidget(buttonReject);

    layoutButtons->setAlignment(Qt::AlignRight);

//    buttonAccept->setSizePolicy(QSizePolicy::Fixed);
//    buttonReject->setSizePolicy(QSizePolicy::Fixed);
}

// Set up the form layout for editing a question
void QuestionEditDialog::setupLayoutForm()
{
    layoutForm = new QFormLayout;
    spinboxPoints = new QSpinBox;
    spinboxPosition = new QSpinBox;
    lineEditQuestion = new QLineEdit;
    lineEditAnswer = new QLineEdit;
    lineEditChoice = new QLineEdit;

    lineEditQuestion->setPlaceholderText("Enter a question");
    lineEditAnswer->setPlaceholderText("Enter the correct answer");
    lineEditChoice->setPlaceholderText("Enter another answer choice");

    layoutForm->addRow("Position", spinboxPosition);
    layoutForm->addRow("Points", spinboxPoints);
    layoutForm->addRow("Question", lineEditQuestion);
    layoutForm->addRow("Answer", lineEditAnswer);
    layoutForm->addRow("Choices", lineEditChoice);

    // add as many line edits as specified by the Quiz object
    for (int i = 0; i < numChoices - 1; ++i) {
        lineEditChoice = new QLineEdit;
        lineEditChoice->setPlaceholderText("Enter another answer choice");
        layoutForm->addRow(" ", lineEditChoice);
    }
}

int QuestionEditDialog::position()
{
    return spinboxPosition->value();
}

int QuestionEditDialog::points()
{
    return spinboxPoints->value();
}

QString QuestionEditDialog::question()
{
    return lineEditQuestion->text();
}

QString QuestionEditDialog::answer()
{
    return lineEditAnswer->text();
}

QStringList QuestionEditDialog::choices()
{
    QStringList choices;
    int rowCount = layoutForm->rowCount();

    for (int row = 4; row < rowCount; ++row) {
        lineEditChoice = (QLineEdit*)layoutForm->itemAt(row, QFormLayout::FieldRole)->widget();
        if (!lineEditChoice->text().isEmpty())
            choices.append(lineEditChoice->text());
    }
    return choices;
}
