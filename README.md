# Heavid
Health + Covid = Heavid (i.e. staying healthy during Covid)

Heavid is a simple GUI application programmed with C++, MySQL, and Qt (www.qt.io) for a Software Engineering Project at Biola University. It was programmed by Misheel Bayarsaikhan, Keziah Charis Bulseco, Luke Ebbinghaus, and Vanessa Garcia and the code is released with the GPL-3.0-only license. It has been tested on Linux/GNU and Mac. For information on the Software Engineering Lifecyle followed, check the Documentation folder.

## Features
- Displays a human diagram that can be selected for Lower Body, Upper Body, and Core
- Displays exercises for the selected muscle group in an exercise list.
- The exercise list can be further filtered by difficulty
- Descriptions and Images for each exercise can be viewed in a separate window
- Exercises can be added to a workout list which can save and load previous workouts
- Both the exercise list and workout list can be minimized

## Screenshot

![Heavid Screenshot](/img/Screen.png "Heavid Screenshot")

## Prerequisites and Set-Up

Since the exercise information is stored in a database, you will need to set up a database server to run Heavid. Use MySQL or Mariadb and a distribution such as XAMPP for the easiest set-up. Once your database is set-up, run <code>source /path/to/file/Heavid.sql</code> to import the Heavid database.

To run Heavid, you will need the following:
- Qt 6 libraries
- MySQL Connector/C++ (https://dev.mysql.com/downloads/connector/cpp/)

To build from source, you will also need:
- qmake
- make

If your MySQL Connector/C++ library is installed in /usr/lib and /usr/include, you don't need any additional steps. Otherwise, you can copy the lib and include folders to the mysql-connector-cpp folder in the Heavid directory.

Database server and login information is stored in database.ini in the Heavid project folder. The default is localhost, root, and no password.

If this does not match your database server or login information, change this. Make sure this database.ini file is placed in the same directory as the Heavid binary.

## Building from Source (Linux)

To build, run:

  <code>qmake</code>
  
  <code>make</code>
  
 And optionally,
 
 <code>make clean && make install</code>
 
 If you run <code>make install</code> and require extra set-up (i.e. MySQL Connector/C++ libraries are not in the /usr/lib directory or your database credentials do not match the Heavid defaults), move database.ini and the mysql-connector-cpp folder to the same directory as the installed binary.

## How To Use

Click on any part of the diagram except the head to display the corresponding exercisese in the exercise list. 
Click another place on the diagram to switch muscle groups, or filter by difficulty by clicking on one of the Beginner, Intermediate, or Advanced tabs. 
If you want to view more information on that exercise, select the exercise on the workout list, then click 'Show Description'. 
To add exercises to the workout list, double-click on the exercise you would like to add.
If you would like to save this workout for a later time, click the 'Save' button and choose a directory. 
Load any saved workout with the 'Load' button. 
If you would like to start the workout list over, press the 'Clear' button.
