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

CONFIG += plugin
QT += designer widgets
TARGET = keysequence_widget
TEMPLATE = lib
#OBJECTS_DIR = ../out/obj
#MOC_DIR = ../out/generated
#UI_DIR = ../out/generated
#RCC_DIR = ../out/generated

SOURCES += \
    keysequence_widget_plugin.cpp \
    keysequence_widget_plugin_collection.cpp \
    keysequence_listwidget_plugin.cpp

HEADERS += \
    keysequence_widget_plugin.hpp \
    keysequence_widget_plugin_collection.hpp \
    keysequence_listwidget_plugin.hpp

include(../keysequence_widget.pri)

build_all:!build_pass {
 CONFIG -= build_all
 CONFIG += release
}

# install
target.path += $$[QT_INSTALL_PLUGINS]/designer

unix{
    LIB_TARGET = lib$${TARGET}.so
}
win32 {
    LIB_TARGET = $${TARGET}.dll
}
creator.files =$$LIB_TARGET
creator.path = $$[QT_INSTALL_PREFIX]/../../Tools/QtCreator/bin/designer
INSTALLS += target creator

