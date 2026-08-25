#include <iostream>
#include "DataManager.h"
#include "modules.h"


int main() {
    DataManager dataManager("geruud.db");
    
    dataManager.createTable();

    bool isRunning = true;
    std::string input;

    while (isRunning) {
        printTitle();

        std::cout << "\033[33mPLAY\033[0m" << std::endl;
        std::cout << "\033[31mEXIT\033[0m" << std::endl;

        std::getline(std::cin, input);

        if (input == "exit" || input == "EXIT") {
            isRunning = false;
        } else if (input == "play" || input == "PLAY") {
            startGame();
            gameLoop();
        } 
        else {
            std::cout << "Unknown command" << input << std::endl;
            system("clear");
            printTitle();
        }
    }

    return 0;
}