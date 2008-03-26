HEADERS     = mainwindow.h \
              sources/*

RESOURCES   = a-iso.qrc
SOURCES     = main.cpp \
              mainwindow.cpp \
              sources/progress.cpp \
              sources/about.cpp \
              sources/options.cpp \
              sources/manual.cpp


OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build

FORMS += ui/options.ui \
         ui/about.ui \
         ui/manual.ui

#wince*: {
#   addFile.sources = example.jpg
#   addFile.path = .
#   DEPLOYMENT += addFile
#}
