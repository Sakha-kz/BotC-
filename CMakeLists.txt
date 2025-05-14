cmake_minimum_required(VERSION 3.10)
project(BotC)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_SOURCE_DIR}/dependencies/boost
    ${CMAKE_SOURCE_DIR}/dependencies/openssl
    ${CMAKE_SOURCE_DIR}/tgbot-cpp/include
)

link_directories(${CMAKE_SOURCE_DIR}/libs)

add_subdirectory(tgbot-cpp)

add_executable(BotC src/main.cpp)

target_link_libraries(BotC
    TgBot
    ssl crypto z
    boost_system
    ws2_32 crypt32
)