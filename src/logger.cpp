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
#include <QTextStream>
#include <QtDebug>
#include <QStandardPaths>

namespace logger
{
QString data_path;
QFile log_file;

// Create directory and file for logs if none exists
bool setup()
{
    QDir dir;
    data_path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    if (!dir.mkpath(data_path))
        return false;

    log_file.setFileName(data_path + "/log");
    log_file.open(QIODevice::Append);

    qInstallMessageHandler(writeMessage);

    return true;
}

void writeMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QTextStream out(&log_file);

    switch (type) {
    case QtDebugMsg:
        out << "Debug: " << localMsg.constData() << " (" << context.file
            << ":" << context.line << ", " << context.function << ")\n";
        break;
    case QtInfoMsg:
        out << "Info: " << localMsg.constData() << " (" << context.file
            << ":" << context.line << ", " << context.function << ")\n";
        break;
    case QtWarningMsg:
        out << "Warning: " << localMsg.constData() << " (" << context.file
            << ":" << context.line << ", " << context.function << ")\n";
        break;
    case QtCriticalMsg:
        out << "Critical: " << localMsg.constData() << " (" << context.file
            << ":" << context.line << ", " << context.function << ")\n";
        break;
    case QtFatalMsg:
        out << "Fatal: " << localMsg.constData() << " (" << context.file
            << ":" << context.line << ", " << context.function << ")\n";
    }
}

}
