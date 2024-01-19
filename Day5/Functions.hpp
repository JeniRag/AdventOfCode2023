#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <map>
#include <vector>
#include "AlmanacList.hpp"
//Header file (Function declaration)

void ReadInput(std::string file_path, AlmanacList &aList);
int64_t FindLowestLocation(std::string file_path);
int64_t FindLowestLocationFromRanges(std::string file_path);



#endif