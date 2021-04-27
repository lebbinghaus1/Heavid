/*
    database.h
    Part of Heavid
    Copyright (C) 2021  Misheel Bayarsaikhan, Keziah Charis Bulseco, Luke Ebbinghaus, Vanessa Garcia

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <QFile>
#include <unordered_map>

#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>

class database
{
public:
    database() {};
    sql::ResultSet * query(std::string);
    std::string createQueryStatement(std::string = "", std::string = "");
    std::string createDescQueryStatement(std::string= "");
    std::unordered_map<std::string, std::string> * readServerInfo();
};

#endif // DATABASE_H
