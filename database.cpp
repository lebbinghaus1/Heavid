#include "database.h"
#include <QTextStream>

sql::ResultSet * database::query(std::string queryStatement)
{
    sql::Driver *driver;
    sql::Connection *connection;
    sql::Statement *statement;
    sql::ResultSet *result{};

    std::unordered_map<std::string, std::string> *config = readServerInfo();

    try {
        driver = get_driver_instance();
        connection = driver -> connect(config->at("server"), config->at("user"), config->at("password"));
        connection -> setSchema("heavid");
        statement = connection -> createStatement();
        result = statement -> executeQuery(queryStatement);
     }
     catch(sql::SQLException &e) {
          std::cout << "ERROR: Cannot connect to the database. "
            "Check that the database server is running and that your credentials are correct." << std::endl;
     }

    delete config;
    //delete serverInfo;

    return result;
}

std::string database::createQueryStatement(std::string muscleGroup, std::string difficultyFilter)
{

    std::string queryStatement = "select ExerciseName from Exercise, Exercise_Has_Muscle, Muscle_Group"
        "\nWhere ExerciseId = Exercise_ExerciseID"
        "\nAnd MuscleId = Muscle_Group_MuscleID";

    if(!muscleGroup.empty())
        queryStatement.append("\nAnd MuscleName = '" + muscleGroup + "'\n");
    if(!difficultyFilter.empty())
        queryStatement.append("\nAnd DifficultyLevel = '" + difficultyFilter + "'");

    return queryStatement;
}

std::string database::createDescQueryStatement(std::string exerciseName)
{

    std::string queryStatement = "select Description from Exercise";

    if(!exerciseName.empty())
        queryStatement.append("\nwhere ExerciseName = '" + exerciseName + "'\n");


    return queryStatement;
}

std::unordered_map<std::string, std::string> * database::readServerInfo()
{
    std::string lines;
    std::unordered_map<std::string, std::string> *config = {new std::unordered_map<std::string, std::string>};
    config->insert({"server", "localhost"});
    config->insert({"user", "root"});
    config->insert({"password", ""});

    int serverLoc;
    int userLoc;
    int passwordLoc;

    QFile file("database.ini");
    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);
    while (!in.atEnd()) {
        lines.append(in.readLine().toStdString() + "\n");
    }

    try {
        serverLoc = lines.find("server=") + std::strlen("server=");
        userLoc = lines.find("user=") + std::strlen("user=");
        passwordLoc = lines.find("password=") + std::strlen("password=");

        if(serverLoc != -1) {
            config->at("server") = lines.substr(serverLoc, lines.substr(serverLoc, lines.length() - serverLoc).find("\n"));
        }
        if(userLoc != -1) {
            config->at("user") = lines.substr(userLoc, lines.substr(userLoc, lines.length() - userLoc).find("\n"));
        }
        if(passwordLoc != -1) {
            config->at("server") = lines.substr(passwordLoc, lines.substr(passwordLoc, lines.length() - passwordLoc).find("\n"));
        }
    }  catch (std::out_of_range &e) {
        std::cout << "WARNING: Database config file is missing or unreadable. "
            "Using default credentials." << std::endl;
    }

    return config;
}
