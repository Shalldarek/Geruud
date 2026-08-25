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

void gameLoop() {
    std::cout << R"(
            _____                 ___ 
           /_____\       o       /___\  
   __v______|___|_______ooo______|___|________v_____________v________________v____
                   v         ____
    v                       /____\      v                         v           v  
   ___________v_____________|____|_____________________v__________________v____________

    )" << std::endl;

    exit(0);
}