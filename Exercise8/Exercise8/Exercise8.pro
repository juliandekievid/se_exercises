TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        carvec2d.cpp \
        commandprocessor.cpp \
        dofxyrz.cpp \
        main.cpp \
        rotationmotor.cpp

HEADERS += \
   cartvec2d.h \
   commandprocessor.h \
   dofxyrz.h \
   rotationmotor.h
