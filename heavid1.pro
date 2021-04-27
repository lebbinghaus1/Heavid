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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/lib/release/ -lmysqlcppconn
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/lib/debug/ -lmysqlcppconn
macx: LIBS += -L$$PWD/../../mysql-connector-c++-1.1.13-macos10.14-x86-64bit/lib/ -lmysqlcppconn.7.1.1.13
unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/ -lmysqlcppconn

INCLUDEPATH += $$PWD/../../../usr/include
DEPENDPATH += $$PWD/../../../usr/include

INCLUDEPATH += $$PWD/../../mysql-connector-c++-1.1.13-macos10.14-x86-64bit/include
DEPENDPATH += $$PWD/../../mysql-connector-c++-1.1.13-macos10.14-x86-64bit/include

INCLUDEPATH += $$PWD/../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../usr/include
