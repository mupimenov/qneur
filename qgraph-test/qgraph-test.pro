TEMPLATE = app
HEADERS += src/HGraphTest.h
SOURCES += src/HGraphTest.cpp src/main.cpp
CONFIG += warn_on
S =
LIBS += ../qgraph/libqgraph.a
PRE_TARGETDEPS += ../qgraph/libqgraph.a
