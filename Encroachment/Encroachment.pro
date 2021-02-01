QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bonus.cpp \
    boss.cpp \
    boss2.cpp \
    bullet.cpp \
    canonbullet.cpp \
    character.cpp \
    enemy.cpp \
    enemybullet.cpp \
    enemyshoots.cpp \
    file.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    login.cpp \
    main.cpp \
    menu.cpp \
    multiplayer.cpp \
    obstacle.cpp \
    obstacle2.cpp \
    portal.cpp \
    power.cpp

HEADERS += \
    bonus.h \
    boss.h \
    boss2.h \
    bullet.h \
    canonbullet.h \
    character.h \
    enemy.h \
    enemybullet.h \
    enemyshoots.h \
    file.h \
    level1.h \
    level2.h \
    level3.h \
    login.h \
    menu.h \
    multiplayer.h \
    obstacle.h \
    obstacle2.h \
    portal.h \
    power.h

FORMS += \
    level1.ui \
    level2.ui \
    level3.ui \
    login.ui \
    menu.ui \
    multiplayer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
