#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <cassert>
#include <numeric>       //for summing ab vector
#include <bits/stdc++.h> //to find maximum of vector
#include <regex>
#include "Race.hpp"


/**
 * @brief reads the input file and stores the time and distances of the reaces
 * 
 * @param file_path directory of input file
 * @param timesAndDistances to store the time values and distances. An 2D vector.
 * @return ** void 
 */
void readInput(std::string file_path, std::vector<std::vector<int>> &timesAndDistances)
{

    

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

        while (getline(inputFile, line))
        {
            std::vector<int> temporaryVector;


            //extract the numerical values
            auto intPos = line.find_first_of("0123456789", 0); // find first integer

            while (intPos != std::string::npos)
            {
                auto intEndPos = line.find_first_not_of("0123456789", intPos);

                std::string numberString = line.substr(intPos, intEndPos - intPos); // extract int
                int number = std::stoi(numberString);                               // convert integer to string

                temporaryVector.push_back(number);

                intPos = line.find_first_of("0123456789", intEndPos);
            }

        timesAndDistances.push_back(temporaryVector);
        }
    }
    return;
}

/**
 * @brief Calculates the number of possible wins for each race and takes the product of thema ll.
 * 
 * @param file_path directory to input file
 * @return ** int product of the possible wins of each gae
 */
int calculateProduct(std::string file_path){
    std::vector<std::vector<int>> timesAndDistances;
    int product = 1;

    readInput(file_path, timesAndDistances);

    for (int i=0; i<timesAndDistances[0].size(); i++){
        long time = timesAndDistances[0][i]; //convert to long
        long distance = timesAndDistances[1][i];

        Race race(time, distance);
        product *= race.getPossibleNumberOfWins();
    }
    return product;
}

/**
 * @brief combines the time and distance values from the input file to two longs each and calculates the number of possible wins.
 * 
 * @param file_path directory to input file
 * @return ** int the possible number of wins
 */
int combineInputAndGetProduct(std::string file_path){
    std::vector<std::vector<int>> timesAndDistances;
   
    std::string time;
    std::string distance;

    readInput(file_path, timesAndDistances);

    //combine all integers to one long value.
    for (int i=0; i<timesAndDistances[0].size(); i++){
        time += std::to_string(timesAndDistances[0][i]);
        distance += std::to_string(timesAndDistances[1][i]);
    }
    
    //create race class with the long values
    Race race (std::stol(time), std::stol(distance));


    return race.getPossibleNumberOfWins();
}