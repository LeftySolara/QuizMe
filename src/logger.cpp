/******************************************************************************
 * logger.cpp : namespace for functions that handle application logging
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

#include "logger.h"
#include <QDir>
#include <QtDebug>
#include <QStandardPaths>

namespace logger
{
QString data_path;
FILE *log_file;

// Create directory and file for logs if none exists
bool setup()
{
    QDir dir;
    data_path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    qDebug() << data_path;
    if (!dir.mkpath(data_path))
        return false;

    QString log_file_path = data_path + "/log";
    FILE *log_file = fopen(log_file_path.toStdString().c_str(), "w");

    return true;
}

}
