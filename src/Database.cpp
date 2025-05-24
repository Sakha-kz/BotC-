#include "Database.h"
#include <sqlite3.h>
#include <iostream>

void Database::testConnection() {
    sqlite3* db;
    int rc = sqlite3_open("data/smartbot.db", &db);
    if (rc) {
        std::cerr << "Не удалось открыть БД: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "БД успешно подключена.\n";
    }
    sqlite3_close(db);
}