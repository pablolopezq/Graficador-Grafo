TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vertice.cpp \
    arista.cpp \
    listaaristas.cpp \
    listavertices.cpp \
    grafo.cpp \
    textedit.cpp \
    userinterface.cpp \
    lineshape.cpp

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/ -lsfml-window

INCLUDEPATH += $$PWD/../../../usr/include/SFML
DEPENDPATH += $$PWD/../../../usr/include/SFML

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/ -lsfml-system

INCLUDEPATH += $$PWD/../../../usr/include/SFML
DEPENDPATH += $$PWD/../../../usr/include/SFML

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/ -lsfml-network

INCLUDEPATH += $$PWD/../../../usr/include/SFML
DEPENDPATH += $$PWD/../../../usr/include/SFML

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/release/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/debug/ -lsfml-graphics
else:unix: LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../../usr/include/SFML
DEPENDPATH += $$PWD/../../../usr/include/SFML

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/ -lsfml-audio

INCLUDEPATH += $$PWD/../../../usr/include/SFML
DEPENDPATH += $$PWD/../../../usr/include/SFML

HEADERS += \
    vertice.h \
    arista.h \
    listaaristas.h \
    listavertices.h \
    grafo.h \
    textedit.h \
    userinterface.h \
    lineshape.h
