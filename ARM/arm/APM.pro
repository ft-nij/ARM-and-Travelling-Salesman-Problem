QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auto.cpp \
    bd.cpp \
    catalog.cpp \
    info.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    sotrudnik.cpp

HEADERS += \
    auto.h \
    bd.h \
    catalog.h \
    info.h \
    mainwindow.h \
    register.h \
    sotrudnik.h

FORMS += \
    auto.ui \
    bd.ui \
    catalog.ui \
    info.ui \
    mainwindow.ui \
    register.ui \
    sotrudnik.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
