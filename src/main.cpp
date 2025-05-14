#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("T");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Привет, я бот!");
    });

    try {
        printf("Бот запущен...\n");
        bot.getApi().deleteWebhook();
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (const std::exception& e) {
        printf("Ошибка: %s\n", e.what());
    }
    return 0;
}