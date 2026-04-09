TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        LZ78.cpp \
        RLE.cpp \
        encriptacion.cpp \
        escritura.cpp \
        lectura.cpp \
        main.cpp \
        rotacionbits.cpp \
        xor.cpp

HEADERS += \
    LZ78.h \
    RLE.h \
    encriptacion.h \
    escritura.h \
    lectura.h \
    rotacionbits.h \
    xor.h

DISTFILES += \
    archivoprueba
