#include "BotCore.h"

int main() {
    const char* token="7647645162:AAGp089P3bqtu1wSz7C-y2lMU2aEMD76oAI";
    if (!token) {
        std::cerr<<"Error: переменная TELEGRAM_TOKEN не установлена."<<'\n';
        return 1;
    }

    BotCore bot(token);
    bot.run();
    return 0;
}