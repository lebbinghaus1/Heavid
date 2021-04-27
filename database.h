#ifndef DATABASE_H
#define DATABASE_H

#include <string>

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
};

#endif // DATABASE_H
