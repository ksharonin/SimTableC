#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#include <map>
#include <tuple>
#include <string>
#include <chrono>
#include <thread>

#include "/Users/katrinasharonin/Downloads/SimTableC++/include/menu.h"
#include "/Users/katrinasharonin/Downloads/SimTableC++/include/board.h"

/* VARIABLES */
int load_duration = 100;

/* FUNCTIONS */

void printMenu() {

    /* SimTableC++ Title */
    std::cout << "\n";
    std::cout << color_codes.find("RED")->second << "=========================================================== \n";
    std::cout << "  _____ _        _______    _     _       _____           \n";
    std::cout << " / ____(_)      |__   __|  | |   | |     / ____|_     _   \n";
    std::cout << "| (___  _ _ __ ___ | | __ _| |__ | | ___| |   _| |_ _| |_ \n";
    std::cout << " \\___ \\| | '_ ` _ \\| |/ _` | '_ \\| |/ _ \\ |  |_   _|_   _| \n";
    std::cout << " ____) | | | | | | | | (_| | |_) | |  __/ |____|_|   |_|  \n";
    std::cout << "|_____/|_|_| |_| |_|_|\\__,_|_.__/|_|\\___|\\_____|          \n";
    std::cout << "=========================================================== \n";
    std::cout << color_codes.find("DEFAULT")->second << "\n";

    /* Description */
    std::cout << "Wildfire Situation Training Simulator by Katrina Sharonin \n \n";

    /* Options */
    std::cout << "[1] Start Game\n";
    std::cout << "[2] Instructions\n";
    std::cout << "[3] Quit\n";

}

void showLoadingBar(int duration) {
    const int barWidth = 50;
    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        std::cout << " ";
    }
    std::cout << "]";

    for (int i = 0; i <= barWidth; ++i) {
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(duration * 20 / barWidth));
        std::cout << "\r[";
        for (int j = 0; j < i; ++j) {
            std::cout << "=";
        }
        for (int j = i; j < barWidth; ++j) {
            std::cout << " ";
        }
        std::cout << "]";
    }
    std::cout << "\n" << std::endl;
}

bool initMenu(){
    /* Returns bool, true if start the game, false otherwise*/

    printMenu();
    std::string user_input;

    while(true) {
        std::cout << "\nEnter number: ";
        std::getline(std::cin, user_input);

        if (user_input == "1") {
            std::cout << "\nLoading new game... \n" << std::endl;
            showLoadingBar(load_duration);
            return true;
        }
        else if (user_input == "2") {
            // TODO: implement instr section
            return false;
        }
        else if (user_input == "3") {
            return false;
        }
        else {
            std::cout << fetchColor("BG_RED") << "\n Invalid input. Please choose an option listed above." << fetchColor("DEFAULT") << std::endl;
        }

    }

    // TODO: never gets here, refactor
    return false;

}