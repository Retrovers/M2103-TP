TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Duree.cpp \
    testDuree.cpp \
    CException.cpp

HEADERS += \
    Duree.h \
    CException.h \
    CstCodErr.h \
    IEditable.hpp
