/******************************************************************************
 * settings.cpp : namespace for functions that deal with application settings
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

#include "settings.h"
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QtDebug>

namespace settings
{

// Check if a settings file exists
bool settingsExist()
{
    QSettings settings;
    QFileInfo settings_file_info(settings.fileName());
    return settings_file_info.exists();
}

bool createSettingsFile()
{
    QSettings settings;
    QFile settings_file;
    QFileInfo settings_file_info(settings.fileName());
    QDir dir;

    if (!dir.mkpath(settings_file_info.path()))
        return false;

    settings_file.setFileName(settings_file_info.filePath());
    settings_file.open(QIODevice::ReadWrite);
    if (!settings_file.exists())
        return false;
    settings_file.close();
    return true;
}

}
