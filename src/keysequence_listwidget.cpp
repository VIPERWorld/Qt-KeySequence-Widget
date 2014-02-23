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

#include "keysequence_listwidget.hpp"
#include "keysequence_widget.hpp"

#include <QAction>
#include <QMenu>
#include <QPushButton>
#include <QHeaderView>
#include <QMainWindow>

KeySequence_ListWidget::KeySequence_ListWidget(QWidget *parent) :
    QTableWidget(parent)
{
    horizontalHeader()->hide();
    verticalHeader()->hide();
    setShowGrid(false);
    setSelectionMode(NoSelection);

    insertColumn(0);
    insertColumn(1);
    insertColumn(2);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void KeySequence_ListWidget::append_row(QAction* action)
{
    int row = rowCount();
    insertRow(row);
    setItem(row,0,new QTableWidgetItem(action->icon(),action->iconText()));
    KeySequence_Widget* ksw = new KeySequence_Widget(action);
    setCellWidget(row,1,ksw);
    QPushButton *clear = new QPushButton(QIcon::fromTheme("edit-clear"),tr("Clear"));
    connect(clear,SIGNAL(clicked()),ksw,SLOT(clear()));
    setCellWidget(row,2,clear);
}

void KeySequence_ListWidget::append_title_row(QString title)
{
    int row = rowCount();
    insertRow(row);
    QTableWidgetItem *item = new QTableWidgetItem(title);
    QFont f = item->font();
    f.setBold(true);
    item->setFont(f);
    setItem(row,0,item);
    setSpan(row,0,1,3);
}

void KeySequence_ListWidget::append_rows(QList<QAction *> actions)
{
    foreach(QAction* act, actions)
        if ( !act->isSeparator() )
            append_row(act);
}

void KeySequence_ListWidget::append_menu(QMenu *menu)
{
    if ( !menu->actions().empty() )
    {
        append_title_row(menu->title().replace('&',""));
        append_rows(menu->actions());
    }
}

void KeySequence_ListWidget::append_window(QMainWindow *window)
{
    foreach(QMenu* menu, window->findChildren<QMenu*>())
        append_menu(menu);
}
