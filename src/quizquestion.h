/******************************************************************************
 * quizquestion.h : parent class for question objects
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

#ifndef QUIZQUESTION_H
#define QUIZQUESTION_H

#include <QString>

class QuizQuestion
{
public:
    QuizQuestion();
    QuizQuestion(int pos, int pts, QString questn, QString ans);

    void setQuestion(QString questn);
    void setCorrectAnswer(QString ans);
    void setPosition(unsigned int pos);
    void setPoints(unsigned int amount);

    QString getQuestion();
    QString getCorrectAnswer();
    unsigned int getPosition();
    unsigned int getPoints();

    // void checkAnswer();


private:
    QString question;
    QString answer;
    unsigned int position;
    unsigned int points;
};

#endif // QUIZQUESTION_H
