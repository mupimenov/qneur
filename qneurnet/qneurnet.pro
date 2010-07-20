HEADERS += src/Synapse.h src/Weights.h src/State.h src/Neurnet.h
SOURCES += src/main.cpp src/Neurnet.cpp
LIBS += ../qgraph/libqgraph.a
PRE_TARGETDEPS += ../qgraph/libqgraph.a
TEMPLATE = app
