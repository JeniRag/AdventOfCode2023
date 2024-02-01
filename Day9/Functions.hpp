#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <map>
#include <vector>
//Header file (Function declaration)
void readInput(std::string file_path, std::vector<std::vector<long>> &inputArrays);
long extrapolateNextValue(const std::vector<long> &oneArray);
long extrapolateBack(const std::vector<long> &oneArray);
//long getSum(std::string file_path);

long getSum(std::string file_path, long(*extrapolate)(const std::vector<long> &oneArray));
#endif