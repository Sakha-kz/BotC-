#pragma once
#include <tgbot/tgbot.h>

class BotCore{
public:
    BotCore(const std::string& token);
    void run();
private:
    TgBot::Bot bot;
    void setup();
};