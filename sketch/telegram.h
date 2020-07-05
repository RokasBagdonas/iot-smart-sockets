#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <ssl_client.h>
#include <WiFiClientSecure.h>

// https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot 
#include "UniversalTelegramBot.h"
#include "private.h"
#include "transmitter.h"

int checkMessages();
void handleNewMessages(int);
void setTelegramApiKey(String);
void resetTelegramApiKey();
void tryToggleSocket(String, int);

#endif
