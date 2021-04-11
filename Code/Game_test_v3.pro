QT       += core gui sql\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Boom.cpp \
    Bullet.cpp \
    Button.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Levels.cpp \
    Menu.cpp \
    Panel.cpp \
    Player.cpp \
    Score.cpp \
    main.cpp

HEADERS += \
    Boom.h \
    Bullet.h \
    Button.h \
    Enemy.h \
    Game.h \
    Health.h \
    Levels.h \
    Menu.h \
    Panel.h \
    Player.h \
    Score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resorce.qrc

DISTFILES += \
    Game_Over.mp3 \
    bg.jpg \
    bg.mp3 \
    boom.mp3 \
    boom.png \
    bullet.mp3 \
    bullet.png \
    enemy.png \
    player.png
