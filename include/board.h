#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#include <map>
#include <tuple>
#include <string>

/* VARIABLES */

#ifndef GLOBALS_H
#define GLOBALS_H

/* LIMITS */
extern int MAX_ROWS;
extern int MAX_COLS;

/* SETTINGS */
extern int ROWS;
extern int COLS;
extern int MILE_CNT; // for 3 cells == x miles
extern char NORTH_DIR; // compass dir
extern std::string CURR_TIME;

/* BOARD STATE */
extern std::map<std::pair<int, int>, std::string> boardState; // TODO: work on making into unordered / O(1) access

/* PRIVATE */
extern std::map<std::string, std::string> color_codes;
extern std::map<std::string, std::string> legend_color;

#endif // GLOBALS_H

/* FUNCTIONS */

std::string fetchColor(std::string input);
void printBoard(int rows, int cols);
void setBoardCell(int row, int col, std::string input);
void initGame();