# Copyright (C) 2013-2014 Mattia Basaglia
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.

QT       += core gui

#OBJECTS_DIR = ../out/obj
#MOC_DIR = ../out/generated
#UI_DIR = ../out/generated
#RCC_DIR = ../out/generated

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = keysequence_widget_demo
TEMPLATE = app


SOURCES += main.cpp \ 
    main_window.cpp


include(../keysequence_widget.pri)

FORMS += \
    main_window.ui

HEADERS += \
    main_window.hpp


