#-------------------------------------------------
#
# Project created by QtCreator 2014-10-06T23:43:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_Python
TEMPLATE = app


SOURCES += main.cpp\
        testpython.cpp

HEADERS  += testpython.h

FORMS    += testpython.ui

# PythonQt
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../PythonQt/lib/release/ -lPythonQt -lPythonQt_QtAll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../PythonQt/lib/debug/ -lPythonQt -lPythonQt_QtAll
else:unix: LIBS += -L$$PWD/../../PythonQt/lib/ -lPythonQt -lPythonQt_QtAll

DYLD_LIBRARY_PATH += $$PWD/../../PythonQt/lib/

INCLUDEPATH += $$PWD/../../PythonQt/src
DEPENDPATH += $$PWD/../../PythonQt/src

# Python 3
INCLUDEPATH += /Library/Frameworks/Python.framework/Versions/3.4/Headers
LIBS += -L/Library/Frameworks/Python.framework/Versions/3.4/lib/python3.4/config-3.4m -ldl -framework CoreFoundation -lpython3.4m
