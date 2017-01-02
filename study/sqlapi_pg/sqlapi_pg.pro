TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
#LIBS += /home/eduardo/C/PostgreSQL/libpqxx-4.0/src/.libs/libpqxx.a
#INCLUDEPATH += /home/eduardo/C/PostgreSQL/libpqxx-4.0/include
LIBS += -lpqxx -lpq
