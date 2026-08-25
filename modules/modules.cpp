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
    std::cout << "Game loop started." << std::endl;
    exit(0);
}