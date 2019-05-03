TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpthread

SOURCES += \
    Archivage.cpp \
    BD.cpp \
    Chrono.cpp \
    InterfaceDeSaisie.cpp \
    kbhit.cpp \
    Capteur.cpp \
    Alarme.cpp \
    Voyant.cpp \
    Clavier.cpp \
    ObjetTempo.cpp \
    Porte.cpp \
    Systeme.cpp \
    main.cpp

HEADERS += \
    Archivage.h \
    BD.h \
    Chrono.h \
    InterfaceDeSaisie.h \
    kbhit.h \
    ObjetTempo.h \
    Capteur.h \
    Alarme.h \
    Voyant.h \
    Clavier.h \
    Porte.h \
    Systeme.h
