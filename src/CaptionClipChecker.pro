TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    src/captiontest.cpp \
    src/captionlist.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
include(QtXlsxWriter/src/xlsx/qtxlsx.pri)

HEADERS += \
    src/captiontest.h \
    src/captionlist.h
