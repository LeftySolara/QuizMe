/******************************************************************************
 * quizquestion.cpp : parent class for question objects
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

#include "quizquestion.h"

QuizQuestion::QuizQuestion()
{
    this->question = QString();
    this->answer = QString();
    this->position = 0;
    this->points = 0;
}

QuizQuestion::QuizQuestion(int pos, int pts, QString questn, QString ans)
{
    this->position = pos;
    this->points = pts;
    this->question = questn;
    this->answer = ans;
}

void QuizQuestion::setQuestion(QString questn)
{
    this->question = questn;
}

void QuizQuestion::setCorrectAnswer(QString ans)
{
    this->answer = ans;
}

void QuizQuestion::setPosition(unsigned int pos)
{
    this->position = pos;
}

void QuizQuestion::setPoints(unsigned int amount)
{
    this->points =amount;
}

QString QuizQuestion::getQuestion()
{
    return this->question;
}

QString QuizQuestion::getCorrectAnswer()
{
    return this->answer;
}

unsigned int QuizQuestion::getPosition()
{
    return this->position;
}

unsigned int QuizQuestion::getPoints()
{
    return this->points;
}
