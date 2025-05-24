#include <BotCore.h>
#include <iostream>

BotCore::BotCore(const std::string& token) : bot(token) {
    setup();
}

void BotCore::setup() {
    bot.getEvents().onCommand("start", [this](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Здорова, я бот!");
    });
}

void BotCore::run(){
    try{
        bot.getApi().deleteWebhook();
        TgBot::TgLongPoll longPoll(bot);
        std::cout<<"Бот запущен"<<'\n';
        while(true){
            longPoll.start();
        }
    } catch (const std::exception& e){
        std::cerr<<"Error: "<<e.what()<<"/n";
    }
}