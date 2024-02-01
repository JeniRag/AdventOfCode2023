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

/**
 * @brief Parses the input file and stores the values in an 2D vector.
 *
 * @param file_path
 * @param inputArrays refernce to the Matrix to store the values.
 * @return ** void
 */
void readInput(std::string file_path, std::vector<std::vector<long>> &inputArrays)
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
            std::vector<long> oneRow;

            // extract the numerical values
            auto intPos = line.find_first_of("-1234567890", 0); //make sure it also reads the minus sign

            while (intPos != std::string::npos)
            {
                auto endPos = line.find_first_not_of("-1234567890", intPos);

                std::string intString = line.substr(intPos, endPos - intPos);
                long element = std::stoi(intString);
                oneRow.push_back(element);

                intPos = line.find_first_of("-1234567890", endPos);

                // key = std::regex_replace(key, std::regex("[\\r\\n\\s]+"), ""); // remove newline characte and spaces
            }

            inputArrays.push_back(oneRow);
        }
    }
    return;
}

bool allElementsSame(const std::vector<long>& vec) {
    auto it = std::adjacent_find(vec.begin(), vec.end(), std::not_equal_to<int>());
    return it == vec.end();
}



long extrapolateNextValue(const std::vector<long> &oneArray)
{

    int N = oneArray.size();

    std::vector<std::vector<long>> allDifferences;

    allDifferences.push_back(oneArray);
   // bool allZero = false;
    bool allElementsEqual = false;
   

    while (!allElementsEqual)
    {
       assert(N>1);
        std::vector<long> differences(N);
        std::adjacent_difference(allDifferences.back().begin(), allDifferences.back().end(), differences.begin()); // y0=x0, y1= x1- x0
        differences.erase(differences.begin());                                                                    // removes first element
        
        allDifferences.push_back(differences);
        
        // check if all values 0
        // allZero = std::all_of(differences.begin(), differences.end(), [](const long element)
        //                       { return element == 0; });

        allElementsEqual = allElementsSame(differences);

        N = differences.size();
     
    }

    // for (int i=0; i<allDifferences.size(); i++){
    //         for (int j=0; j< allDifferences[i].size(); j++){
    //         std::cout<<allDifferences[i][j] <<", ";
    //     }
    //     std::cout<<std::endl;
    // }

    long interpolatedElement =  allDifferences.back().back();

    for (int i = allDifferences.size() - 1; i > 0; i--)
    {

        interpolatedElement = allDifferences[i - 1].back() + interpolatedElement;
    }

    return interpolatedElement;
}

long extrapolateBack(const std::vector<long> &oneArray)
{

    int N = oneArray.size();

    std::vector<std::vector<long>> allDifferences;

    allDifferences.push_back(oneArray);
   // bool allZero = false;
    bool allElementsEqual = false;
   

    while (!allElementsEqual)
    {
       assert(N>1);
        std::vector<long> differences(N);
        std::adjacent_difference(allDifferences.back().begin(), allDifferences.back().end(), differences.begin()); // y0=x0, y1= x1- x0
        differences.erase(differences.begin());                                                                    // removes first element
        
        allDifferences.push_back(differences);
        
        // check if all values 0
        // allZero = std::all_of(differences.begin(), differences.end(), [](const long element)
        //                       { return element == 0; });

        allElementsEqual = allElementsSame(differences);

        N = differences.size();
     
    }


    long interpolatedElement =  allDifferences.back().front();

    for (int i = allDifferences.size() - 1; i > 0; i--)
    {

        interpolatedElement = allDifferences[i - 1].front() - interpolatedElement;
    }

    return interpolatedElement;
}



long getSum(std::string file_path, long(*extrapolate)(const std::vector<long> &oneArray))
{

    // TODO: write enum for task an choose extrapolate function.
    std::vector<std::vector<long>> inputArray;
    readInput(file_path, inputArray);

    std::cout << std::endl;
    
    long sum = 0;
    for (int i = 0; i < inputArray.size(); i++)
    {
        
        long value = extrapolate(inputArray[i]); //extrapolateNextValue(inputArray[i]);

        sum += value;
    }

    return sum;
}