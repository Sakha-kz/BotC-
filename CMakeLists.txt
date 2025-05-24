cmake_minimum_required(VERSION 3.10)
project(SmartAssistantBot)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include/boost
    ${CMAKE_SOURCE_DIR}/include/openssl
    ${CMAKE_SOURCE_DIR}/include/tgbot-cpp/include
    ${CMAKE_SOURCE_DIR}//include
)

link_directories(
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_SOURCE_DIR}/libs/sqlite
)

add_subdirectory(include/tgbot-cpp)

add_executable(SmartAssistantBot 
    src/main.cpp
    src/BotCore.cpp
    src/Command.cpp    
    src/Command.h
    src/Task.cpp    
    src/Task.h
    src/Database.cpp    
    src/Database.h    
)

target_link_libraries(SmartAssistantBot
    TgBot
    ssl crypto z
    boost_system
    sqlite3
)

if(WIN32)
    target_link_libraries(SmartAssistantBot ws2_32 crypt32)
endif()