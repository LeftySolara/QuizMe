/******************************************************************************
 * question.h : class for representing quiz questions
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

#ifndef QUESTION_H
#define QUESTION_H

#define DEFAULT_QUESTION "Enter question here"
#define DEFAULT_ANSWER "Enter answer here"

#include <QStringList>

class Question
{
public:
    Question(QString qstn = DEFAULT_QUESTION, QString ans = DEFAULT_ANSWER,
             QStringList options = QStringList());

    void set_question(QString question);
    void set_answer(QString answer);

    QString get_question();
    QString get_answer();
private:
    QString question;
    QString answer;
    QStringList choices;
};

#endif // QUESTION_H
