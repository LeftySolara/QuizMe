/******************************************************************************
 * multichoicequestion.h : a multiple-choice question
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

#ifndef MULTICHOICEQUESTION_H
#define MULTICHOICEQUESTION_H

#include "quizquestion.h"
#include <QString>
#include <QStringList>


class MultiChoiceQuestion : public QuizQuestion
{
friend class QuestionForm;

public:
    MultiChoiceQuestion() : QuizQuestion() {}

    MultiChoiceQuestion(int pos, int pts, QString questn, QString ans, QStringList options)
    : QuizQuestion(pos, pts, questn, ans)
    {
        options.append(ans);
        this->choices = options;
    }

    bool checkAnswer(QString chosen_option);
    bool setCorrectAnswer(QString ans);
    void setChoices(QStringList list);
    void shuffleChoices();

private:
    QStringList choices;
};

#endif // MULTICHOICEQUESTION_H
