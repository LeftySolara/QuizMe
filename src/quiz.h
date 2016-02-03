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

#include "quizquestion.h"
#include "questionlayout.h"
#include <QVector>

class Quiz
{
public:
    Quiz();
    void addQuestion(QuizQuestion question);
    void removeQuestion(int position);
    void setupForm();

private:
    QVector<QuizQuestion> questions;
    QuestionLayout *layout;
};

#endif // QUIZ_H
