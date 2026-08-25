#include "modules.h"
#include <iostream>
#include <unistd.h>

void printTitle() {
    std::cout << R"(
     ███  █████ ████  █   █ █   █ ████  
    █     █     █   █ █   █ █   █ █   █ 
    █  ██ ████  ████  █   █ █   █ █   █ 
    █   █ █     █  █  █   █ █   █ █   █ 
     ███  █████ █   █  ███   ███  ████  
    )" << std::endl;
}

void startGame() {
    system("clear");
    std::cout << "Starting the game." << std::endl;
    sleep(1); 
    system("clear");
    std::cout << "Starting the game.." << std::endl;
    sleep(2);
    system("clear");
    std::cout << "Starting the game..." << std::endl;
    sleep(2);
    system("clear");
}

void mainCity() {
    std::cout << R"(
            _____                 ___ 
           /_____\       o       /___\  
   __v______|___|_______ooo______|___|________v_____________v________________v____
                   v         ____
    v                       /____\      v                         v           v  
   ___________v_____________|____|_____________________v__________________v____________

    )" << std::endl;
    std::cout << std::endl;
}

void gameLoop() {
    bool isRunning = true;
    std::string input;

    while (isRunning) {
        mainCity();
        std::cout << "Your city comprises of 3 yurts and a village campfire. There live 7 people." << std::endl;
        std::cout << "1. Build a new yurt" << std::endl;
        std::cout << "2. Recruit new people from the surrounding areas." << std::endl;
        std::cout << "3. Gather horses" << std::endl;
        std::cout << std::endl;

        std::getline(std::cin, input);

        if (input == "1") {
            std::cout << "You have built a new yurt." << std::endl;
        } else if (input == "2") {
            std::cout << "You have recruited new people." << std::endl;
        } else if (input == "3") {
            std::cout << "You have gathered horses." << std::endl;
        } else {
            std::cout << "Unknown command: " << input << std::endl;
        }
    }
}