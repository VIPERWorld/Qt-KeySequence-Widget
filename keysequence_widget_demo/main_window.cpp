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

#include "main_window.hpp"

Main_Window::Main_Window(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    keysequence_widget->setAttachedAction(action_Action2);
    action_Action2->setShortcut(QKeySequence::Open);
}

void Main_Window::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}
