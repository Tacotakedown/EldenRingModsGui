//
// Created by Taco on 6/11/2024.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace Config {
    struct ConfigStructure {
        std::string greeting;
    };

    struct newConfigParams {
        std::string name;
    };

    class Config {
    public:
        Config();

        ~Config();

        void newConfig(newConfigParams params);

        ConfigStructure openConfig(std::string name);
    };
}


#endif //CONFIG_H
