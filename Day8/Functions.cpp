#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <cassert>
#include <numeric> //for summing ab vector
#include <bits/stdc++.h>
#include <regex>
#include <algorithm>
#include "Maps.hpp"
/**
 * @brief Reads the input file and parses it.
 * 
 * @param file_path directory to input data
 * @param directions string to store the direction (first line of the input file)
 * @param dictionary dictionary to store the individual nodes
 * @return ** void 
 */
void readInput(std::string file_path, std::string &directions, std::map<std::string, std::vector<std::string>> &dictionary)
{
    // Parsing the input file

    std::fstream inputFile;

    // open file
    inputFile.open(file_path, std::ios::in);

    // return error if file can't be opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return;
    }

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        int lineIndex = 0;

        while (getline(inputFile, line))
        {
            if (lineIndex == 0)
            {
                directions = std::regex_replace(line, std::regex("\\r\\n|\\r|\\n"), ""); // remove newline characte
            }

            // extract the numerical values
            auto equalPos = line.find_first_of("=", 0); // find location of =

            if (equalPos != std::string::npos)
            {

                std::string key = line.substr(0, equalPos);                      // string on left side
                key = std::regex_replace(key, std::regex("[\\r\\n\\s]+"), ""); // remove newline characte and spaces
                
                std::string rightSide = line.substr(equalPos + 1);
                rightSide = std::regex_replace(rightSide, std::regex("[\\r\\n\\s]+"), "");

                std::stringstream rightStream(rightSide);
                std::string element;
                std::vector<std::string> elementVector;

                while (getline(rightStream, element, ','))
                {
                    element.erase(remove(element.begin(), element.end(), '('), element.end()); // remove brackets
                    element.erase(remove(element.begin(), element.end(), ')'), element.end()); // remove brackets
                    elementVector.push_back(element);
                }

                // populate dictionary
                dictionary.insert({key, elementVector});
            }

            lineIndex += 1;
        }
    }
    return;
}

/**
 * @brief Get the Number Of Steps needed to reach destination
 * 
 * @param file_path directory to input data
 * @param start string that contains the starting node
 * @param destination string that contains the destination node
 * @return ** int 
 */
int getNumberOfSteps(std::string file_path, std::string start, std::string destination)
{

    std::string directions;
    std::map<std::string, std::vector<std::string>> dictionary;

    readInput(file_path, directions, dictionary);
    Maps graph(directions, dictionary);
    int steps = graph.followMap(start, destination);

    return steps;
}