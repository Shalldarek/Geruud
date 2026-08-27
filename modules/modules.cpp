#include "modules.h"
#include <iostream>
#include "DataManager.h"
#include <sqlite3.h>
#include <unistd.h>
#include <random>

void printTitle()
{
    std::cout << R"(
     ███  █████ ████  █   █ █   █ ████  
    █     █     █   █ █   █ █   █ █   █ 
    █  ██ ████  ████  █   █ █   █ █   █ 
    █   █ █     █  █  █   █ █   █ █   █ 
     ███  █████ █   █  ███   ███  ████  
    )" << std::endl;
}

void startGame()
{
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

void mainCity()
{
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

void gameLoop()
{
    DataManager dataManager("geruud.db");
    bool isRunning = true;
    std::string input;

    while (isRunning)
    {
        mainCity();

        int num_of_yurts = dataManager.getNumberOfYurts();
        int num_of_people = dataManager.getNumberOfPeople();
        int num_of_camp_fires = dataManager.getNumberOfCampFires();

        std::cout << "Your city comprises of " << num_of_yurts << " yurts and " << num_of_camp_fires << " campfires. There live " << num_of_people << " people." << std::endl;
        std::cout << "1. Gather people from the surrounding areas." << std::endl;
        std::cout << "2. Gather horses from the surrounding areas." << std::endl;
        std::cout << std::endl;

        std::getline(std::cin, input);

        if (input == "1") {
            system("clear");
            gatherPeople();
        }
        else if (input == "2") {
            system("clear");
            gatherHorses();
        }
        else
        {
            system("clear");
            std::cout << "Unknown command: " << input << std::endl;
        }
    }
}

void gatherPeople()
{
    DataManager dataManager("geruud.db");

    int num_of_people_found = rand() % 4 + 0; 
    std::cout << "Finding new people requires some time." << std::endl;
    sleep(2);
    system("clear");
    std::cout << "Finding new people requires some time.." << std::endl;
    sleep(2);
    system("clear");
    std::cout << "Finding new people requires some time..." << std::endl;
    sleep(2);
    system("clear");
    
    if (num_of_people_found > 0) {
        std::cout << "You have found " << num_of_people_found << " new people!" << std::endl;
        dataManager.addPeople(num_of_people_found);
    } else {
        std::cout << "Unfortunately, you didn't find any new people." << std::endl;
    }
}


void gatherHorses() {
    DataManager dataManager("geruud.db");

    int num_of_horses_found = rand() % 4 + 0; 
    std::cout << "Finding new horses requires some time." << std::endl;
    sleep(2);
    system("clear");
    std::cout << "Finding new horses requires some time.." << std::endl;
    sleep(2);
    system("clear");
    std::cout << "Finding new horses requires some time..." << std::endl;
    sleep(2);
    system("clear");
    
    if (num_of_horses_found > 0) {
        std::cout << "You have found " << num_of_horses_found << " new horses!" << std::endl;
        dataManager.addHorses(num_of_horses_found);
    } else {
        std::cout << "Unfortunately, you didn't find any new horses." << std::endl;
    }
}

