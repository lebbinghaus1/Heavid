QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    exercise_description.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    database.h \
    exercise_description.h \
    mainwindow.h

FORMS += \
    exercise_description.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

unix:!macx: LIBS += -L/usr/lib/ -L$$PWD/mysql-connector-c++/lib/ -lmysqlcppconn
macx:|win32: LIBS += -L$$PWD/mysql-connector-c++/lib/ -lmysqlcppconn

INCLUDEPATH += -I$$PWD/mysql-connector-c++/include -I/usr/include
DEPENDPATH += -I$$PWD/mysql-connector-c++/include -I/usr/include

