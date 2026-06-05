TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        LZ78.cpp \
        RLE.cpp \
        archivos.cpp \
        encriptacion.cpp \
        main.cpp \
        menu.cpp

HEADERS += \
    LZ78.h \
    RLE.h \
    archivos.h \
    encriptacion.h \
    menu.h

DISTFILES += \
    archivoprueba

RESOURCES +=
