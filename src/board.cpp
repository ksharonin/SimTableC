/**
 * @file board.cpp
 * @author Katrina Sharonin
 * @brief board state, color display
 * 
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#include <map>
#include <tuple>
#include <string>

#include "/Users/katrinasharonin/Downloads/SimTableC++/include/board.h"

/* DEFINE VARIABLES */

/* LIMITS */
int MAX_ROWS = 26;
int MAX_COLS = 100;

/* SETTINGS */
int ROWS = 26;
int COLS = 22;
int MILE_CNT = 3; // for 3 cells == x miles
char NORTH_DIR = '^'; // compass dir
std::string CURR_TIME = "13:57 PDT";

/* BOARD STATE */
std::map<std::pair<int, int>, std::string> boardState; // TODO: work on making into unordered / O(1) access

/* PRIVATE */

std::map<std::string, std::string> color_codes = {
    // Basic text colors
    {"DEFAULT", "\033[0m"},
    {"BLACK", "\033[30m"},
    {"RED", "\033[31m"},
    {"GREEN", "\033[32m"},
    {"YELLOW", "\033[33m"},
    {"BLUE", "\033[34m"},
    {"MAGENTA", "\033[35m"},
    {"CYAN", "\033[36m"},
    {"WHITE", "\033[37m"},
    
    // Bright text colors
    {"BRIGHT_BLACK", "\033[90m"},
    {"BRIGHT_RED", "\033[91m"},
    {"BRIGHT_GREEN", "\033[92m"},
    {"BRIGHT_YELLOW", "\033[93m"},
    {"BRIGHT_BLUE", "\033[94m"},
    {"BRIGHT_MAGENTA", "\033[95m"},
    {"BRIGHT_CYAN", "\033[96m"},
    {"BRIGHT_WHITE", "\033[97m"},
    
    // Background colors
    {"BG_BLACK", "\033[40m"},
    {"BG_RED", "\033[41m"},
    {"BG_GREEN", "\033[42m"},
    {"BG_YELLOW", "\033[43m"},
    {"BG_BLUE", "\033[44m"},
    {"BG_MAGENTA", "\033[45m"},
    {"BG_CYAN", "\033[46m"},
    {"BG_WHITE", "\033[47m"},
    
    // Bright background colors
    {"BG_BRIGHT_BLACK", "\033[100m"},
    {"BG_BRIGHT_RED", "\033[101m"},
    {"BG_BRIGHT_GREEN", "\033[102m"},
    {"BG_BRIGHT_YELLOW", "\033[103m"},
    {"BG_BRIGHT_BLUE", "\033[104m"},
    {"BG_BRIGHT_MAGENTA", "\033[105m"},
    {"BG_BRIGHT_CYAN", "\033[106m"},
    {"BG_BRIGHT_WHITE", "\033[107m"}
};

std::map<std::string, std::string> legend_color = {
    {"_X", "BG_RED"},                       // fire
    {"~~", "BG_BLUE"},                      // water
    {"\033[4mT6\033[0m", "BRIGHT_GREEN"},   // type 6 eng
    {"\033[4mT3\033[0m", "GREEN"},          // type 3 eng
    {"_/", "DEFAULT"},                      // slopes
    {"//", "DEFAULT"},
    {"\\_", "DEFAULT"},
    {"\\\\_", "DEFAULT"}
};

/* FUNCTIONS */

std::string fetchColor(std::string input) {
    /* Directly consult color mapping */
    return color_codes.find(input)->second;
}

void setBoardCell(int row, int col, std::string input) {
    /* Bounds check */
    assert(row < ROWS);
    assert(col < COLS);

    /* Set cell in global row/col mapping*/
    boardState[std::make_pair(row, col)] = input;
    return;
}

void printBoard(int rows, int cols) {

    /* check 1: rows cannot exceed alphabe len*/
    assert(rows <= MAX_ROWS);

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<int> numerics(100);
    std::iota(std::begin(numerics), std::end(numerics), 0);

    for (int i = 0; i < rows; ++i) {
        std::cout << alphabet[i];
        for (int j = 0; j < cols; ++j) {

            /* Check if square is set in board state */
            std::pair<int, int> searchPair = std::make_pair(i, j);

            if (boardState.find(searchPair) != boardState.end()) {
                /* Fetch color */
                // TODO: add try-catch if marker defined (but internal issue...)
                std::string color = color_codes.find(legend_color.find(boardState[searchPair])->second)->second;

                /* Set state*/
                std::cout << "|" << color << boardState[searchPair] << color_codes.find("DEFAULT")->second;

            }
            else {
                /* Default square*/
                std::cout << "|__";
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << " ";
    for (int j = 0; j < cols; ++j) {
        if (numerics[j] < 10) {
            std::cout << "  " << numerics[j];
        } else {
            std::cout << " " << numerics[j];
        }
    }
    std::cout << "\n" << std::endl;

    /* Mile len*/
    std::cout << " |________| " << MILE_CNT << " MILES"; 
    /* Compass direction */
    std::cout << "    " << NORTH_DIR << " NORTH";
    /* Time */
    std::cout << "    " << "TIME: " << CURR_TIME << "\n" << std::endl;
}

void initGame() {

    /* MANUAL TESTS */
    setBoardCell(13, 6, "_X");
    setBoardCell(14, 7, "_X");
    setBoardCell(23, 10, "~~");
    setBoardCell(23, 11, "~~");
    setBoardCell(24, 11, "~~");
    setBoardCell(22, 11, "\033[4mT6\033[0m");
    setBoardCell(14, 15, "\033[4mT3\033[0m");
    setBoardCell(13, 14, "_/");
    setBoardCell(12, 14, "_/");
    setBoardCell(11, 14, "_/");

    /* DISPLAY BOARD */
    printBoard(ROWS, COLS);

    return;
}