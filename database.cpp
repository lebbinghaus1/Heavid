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
        connection = driver -> connect("localhost", "root", "");
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
