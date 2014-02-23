/**

\file

\author Mattia Basaglia

\section License

Copyright (C) 2014  Mattia Basaglia

This is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "ui_main_window.h"

class Main_Window : public QMainWindow, private Ui::Main_Window
{
    Q_OBJECT

public:
    explicit Main_Window(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);
};

#endif // MAIN_WINDOW_HPP
