/******************************************************************************
 * multichoicequestion.cpp : a multiple-choice question
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

#include "multichoicequestion.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

bool MultiChoiceQuestion::checkAnswer(QString chosen_option)
{
    return chosen_option == answer;
}

void MultiChoiceQuestion::shuffleChoices()
{
    std::srand (unsigned(std::time(0)));
    std::random_shuffle(choices.begin(), choices.end());
}
