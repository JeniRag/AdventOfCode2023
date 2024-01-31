#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <map>
#include <vector>
//Header file (Function declaration)
void readInput(std::string file_path, std::vector<std::vector<int>> &inputArrays);
int extrapolateNextValue(const std::vector<int> &oneArray);
int getSum(std::string file_path);

#endif