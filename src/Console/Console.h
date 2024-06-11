//
// Created by Taco on 6/11/2024.
//

#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include <string>
#include <mutex>


namespace Console {
    struct ConsoleInit {
        size_t maxLength;
        std::string greeting;
    };

    class Console {
    public:
        Console(ConsoleInit init);

        ~Console();

        void AddToLog(const std::string &log);

        std::vector<std::string> getLogs() const;

    private:
        std::vector<std::string> logs;
        size_t maxLength;
        mutable std::mutex logMutex;
    };
}


#endif //CONSOLE_H
