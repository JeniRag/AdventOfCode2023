#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <map>
#include <vector>
//Header file (Function declaration)

void readInput(std::string file_path, std::string &directions, std::map<std::string, std::vector<std::string>> &dictionary);
int getNumberOfSteps(std::string file_path, std::string start, std::string destination);

#endif