/**
 * @file main.cpp
 * @author Katrina Sharonin
 * @brief main entry for SimTable program
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* Libraries */
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#include <map>
#include <tuple>
#include <string>

/* Project */
#include "/Users/katrinasharonin/Downloads/SimTableC++/include/menu.h"
#include "/Users/katrinasharonin/Downloads/SimTableC++/include/board.h"

int main() {

    /* Menu */
    bool start_game = initMenu();

    /* Game Entry */
    if (start_game) {
        initGame();
    }

    std::cout << "\nExiting the game... \n" << std::endl;
    return 0;
}
