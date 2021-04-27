#include "database.h"
#include <string>

sql::ResultSet * database::query(std::string queryStatement)
{
    sql::Driver *driver;
    sql::Connection *connection;
    sql::Statement *statement;
    sql::ResultSet *result{};

    try {
        driver = get_driver_instance();
        connection = driver -> connect("127.0.0.1", "root", "root");
        connection -> setSchema("heavid");
        statement = connection -> createStatement();
        result = statement -> executeQuery(queryStatement);
     }
     catch(sql::SQLException &e) {
          std::cout << "Error connecting to the database" << std::endl;
     }

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
