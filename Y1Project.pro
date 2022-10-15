QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admindialog.cpp \
    adminview.cpp \
    bookingsearch.cpp \
    customersearch.cpp \
    customerview.cpp \
    detailsdialog.cpp \
    hotelbookdialog.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    registerdialog.cpp

HEADERS += \
    admindialog.h \
    adminview.h \
    bookingsearch.h \
    customersearch.h \
    customerview.h \
    detailsdialog.h \
    hotelbookdialog.h \
    logindialog.h \
    mainwindow.h \
    registerdialog.h

FORMS += \
    admindialog.ui \
    adminview.ui \
    bookingsearch.ui \
    customersearch.ui \
    customerview.ui \
    detailsdialog.ui \
    hotelbookdialog.ui \
    logindialog.ui \
    mainwindow.ui \
    registerdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
