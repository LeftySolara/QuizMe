/******************************************************************************
 * question.cpp : implementation for Question class
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

#include "question.h"


Question::Question(QString qstn, QString ans, QStringList options)
{
    this->question = qstn;
    this->answer = ans;
    this->choices = options;
}

void Question::set_question(QString qstn)
{
    this->question = qstn;
}

void Question::set_answer(QString ans)
{
    this->answer = ans;
}

QString Question::get_question()
{
    return this->question;
}

QString Question::get_answer()
{
    return this->answer;
}
