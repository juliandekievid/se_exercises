TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        commandprocessor.cpp \
        main.cpp \
        rotationmotor.cpp

HEADERS += \
   commandprocessor.h \
   rotationmotor.h
