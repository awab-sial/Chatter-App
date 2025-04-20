QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    after_login.cpp \
    g_c.cpp \
    g_c_inbox.cpp \
    inbox.cpp \
    main.cpp \
    mainwindow.cpp \
    message_send.cpp \
    signup.cpp

HEADERS += \
    after_login.h \
    g_c.h \
    g_c_inbox.h \
    inbox.h \
    mainwindow.h \
    message_send.h \
    signup.h

FORMS += \
    after_login.ui \
    g_c.ui \
    g_c_inbox.ui \
    inbox.ui \
    mainwindow.ui \
    message_send.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    3rd.qrc \
    Resources.qrc \
    real.qrc
