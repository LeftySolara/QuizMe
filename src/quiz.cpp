/******************************************************************************
 * quiz.cpp : a collection of quiz questions
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

#include "quiz.h"

Quiz::Quiz()
{
    possiblePoints = 0;
}

Quiz::Quiz(QList<Question> questions)
{
    questionList = questions;

    possiblePoints = 0;
    for (Question q : questionList)
        possiblePoints += q.points;
}

void Quiz::addQuestion(QString prompt, QString answer, std::array<QString, CHOICE_ARRAY_SIZE> choices,
                       int position, int points)
{
    Question q;

    q.prompt = prompt;
    q.correctAnswer = answer;
    q.choices = choices;
    q.points = points;

    if (position < 0)
        q.id = questionList.size() + 1;
    else
        q.id = position;
}

void Quiz::removeQuestion(int pos)
{
    questionList.removeAt(pos);
}

void Quiz::sort()
{
    if (questionList.size() <= 1)
        return;

    // mergesort?
}

// Returns the number of items in the question list as the number of rows in the model.
int Quiz::rowCount(const QModelIndex &parent) const
{
    return questionList.size();
}

// Returns the number of fields in the first question as the number of columns in the model.
// Every row should have the same number of columns.
int Quiz::columnCount(const QModelIndex &parent) const
{
    // Number of choices + id, points, prompt, and answer fields
    return questionList[0].choices.max_size() + 4;
}

// Returns the appropriate value for the data requested.
// If an invalid index or a role other than DisplayRole is given,
// returns an invalid QVariant.
QVariant Quiz::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        int row = index.row();
        int col = index.column();

        if (col == 0)
            return questionList[row].id;
        else if (col == 1)
            return questionList[row].points;
        else if (col == 2)
            return questionList[row].prompt;
        else if (col == 3)
            return questionList[row].correctAnswer;
        else if (col > 3 && col < CHOICE_ARRAY_SIZE + 3)
            return questionList[row].choices[col-3];
    }
    return QVariant();
}

// Returns the appropriate header string depending on the orientation of the
// header and the section. If anything other than the display role is requested,
// return an invalid QVariant.
QVariant Quiz::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {

        switch (section) {
        case 0:
            return QString("ID");
        case 1:
            return QString("Points");
        case 2:
            return QString("Prompt");
        case 3:
            return QString("Answer");
        default:
            return QString("Choice %1").arg(section-3);
        }
    }
    else
        return QString(" ");
}

// Sets the value of the data in the given model index.
// If an invalid index is given, returns false.
bool Quiz::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int row = index.row();
    int col = index.column();

    if (col == 0)
        questionList[row].id = value.toInt();
    else if (col == 1)
        questionList[row].points = value.toInt();
    else if (col == 2)
        questionList[row].prompt = value.toString();
    else if (col == 3) {
        questionList[row].correctAnswer = value.toString();
        questionList[row].choices[0] = value.toString();
    }
    else if (col > 3 && col < CHOICE_ARRAY_SIZE + 3)
        questionList[row].choices[col-3] = value.toString();

    emit dataChanged(index, index);
    return true;

}
