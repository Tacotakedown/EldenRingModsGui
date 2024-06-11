//
// Created by Taco on 6/11/2024.
//

#include "Console.h"

namespace Console {
    Console::Console(ConsoleInit init) : maxLength(init.maxLength) {
        if (!init.greeting.empty()) {
            AddToLog(init.greeting);
        }
    }

    Console::~Console() {
    }

    void Console::AddToLog(const std::string &log) {
        std::lock_guard<std::mutex> lock(logMutex);
        logs.push_back(log);
        if (maxLength > 0 && logs.size() > maxLength) {
            logs.erase(logs.begin());
        }
    }

    std::vector<std::string> Console::getLogs() const {
        std::lock_guard<std::mutex> lock(logMutex);
        return logs;
    }
}
