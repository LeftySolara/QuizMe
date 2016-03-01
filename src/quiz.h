/******************************************************************************
 * quiz.h : a collection of quiz questions
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

#ifndef QUIZ_H
#define QUIZ_H

#include <QString>
#include <QStringList>


struct Question
{
    QString prompt;
    QString correctAnswer;
    QStringList choices;        // includes the correct answer
    int points;
    int position;
};

class Quiz
{
public:
    Quiz();
    Quiz(QList<Question> questions);
    void addQuestion(QString prompt, QString answer, QStringList choices,
                     int position = -1, int points = 1);
    void removeQuestion(int pos);
//    void shuffle();
    void sort();

private:
    QList<Question> questionList;
    int possiblePoints;
};

#endif // QUIZ_H
