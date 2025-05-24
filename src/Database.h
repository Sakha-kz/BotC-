#pragma once

#include <string>
#include <vector>
#include <sqlite3.h>

class Database {
public:
    Database(const std::string& dbPath);
    ~Database();

    bool open();
    void close();

    bool execute(const std::string& query);
    std::vector<std::vector<std::string>> select(const std::string& query);

    bool addTask(int userId, const std::string& title);
    std::vector<std::pair<int, std::string>> getTasks(int userId);
    bool completeTask(int taskId);

    void testConnection();

private:
    std::string databasePath;
    sqlite3* db;

    bool executeInternal(const std::string& query, sqlite3_stmt** stmt);
};