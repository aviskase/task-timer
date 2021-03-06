/****************************************************************************
 **
 ** Copyright (C) 2018 Yuliya Bagriy.
 **
 ** Copyright (C) 2012 Dmitriy Sukharev.
 ** All rights reserved.
 ** Contact: Dmitriy Sukharev (ecuna@mail.ru)
 **
 ** This file is part of Task Timer.
 **
 ** Task Timer is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as published
 ** by the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** Task Timer is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public License
 ** along with Task Timer.  If not, see <http://www.gnu.org/licenses/>.
 **
 ****************************************************************************/

#ifndef MAIN_WINDOW_PRESENTER_H
#define MAIN_WINDOW_PRESENTER_H

#include <QObject>
#include <QSystemTrayIcon>
#include "runner.h"
#include "mainwindow.h"
#include "systemtray.h"

class MainWindow;
class SystemTray;
class OptionsDialog;

class MainWindowPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowPresenter(QObject *parent = 0, Runner* runner = 0);
    void initWindow(MainWindow*);
    void init(SystemTray*);


signals:

public slots:
    void timeOut(QString timer_type);
    void recommendTask();
    void recommendShortBreak();
    void recommendLongBreak();
    void updateTime();
    void handleTrayIconActivation(QSystemTrayIcon::ActivationReason);

    void startTask();
    void startShortBreak();
    void startLongBreak();
    void pause();
    void resume();
    void options();
    void quit();

private:
    MainWindow* mainWindow;
    SystemTray* systemTray;
    Runner* runner;
    OptionsDialog* optionsDialog;
};

#endif // MAIN_WINDOW_PRESENTER_H
