HEADERS     = mainwindow.h \
              sources/*

RESOURCES   = a-iso.qrc
SOURCES     = main.cpp \
              mainwindow.cpp \
              sources/progress.cpp \
              sources/about.cpp


OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

#wince*: {
#   addFile.sources = example.jpg
#   addFile.path = .
#   DEPLOYMENT += addFile
#}
