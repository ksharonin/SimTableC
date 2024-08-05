#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#include <map>
#include <tuple>
#include <string>

#include "/Users/katrinasharonin/Downloads/SimTableC++/include/board.h"

/* VARIABLES */

/* Maps description <-> weather, start time*/
extern std::map<std::string, std::vector<std::string>> SITUATION_COLLECTION;
/* Possible resource types */
extern std::vector<std::string> RESOURCE_COLLECTION;

/* FUNCTIONS */

/* Generates quantity of resources e.g. 3 type 6 engines, 0 air, 0 dozer */
void genResourceNumber();

/* Randomly select from SITUATION_COLLECTION 
and RESOURCE_COLLECTION (gens # of resources) */
state_collection genSimulation();
