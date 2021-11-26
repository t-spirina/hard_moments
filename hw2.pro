TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17
SOURCES += \
        main.cpp \
    countfromfile.cpp \
    vowelscount.cpp

HEADERS += \
    header.h \
    timer.h \
    countfromfile.h \
    vowelscount.h
