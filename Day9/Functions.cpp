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

void readInput(std::string file_path, std::vector<std::vector<int>> &inputArrays)
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
            std::vector<int> oneRow;

            // extract the numerical values
            auto intPos = line.find_first_of("1234567890", 0);

            while (intPos != std::string::npos)
            {
                auto endPos = line.find_first_not_of("1234567890", intPos);

                std::string intString = line.substr(intPos, endPos - intPos);
                int element = std::stoi(intString);
                oneRow.push_back(element);

                intPos = line.find_first_of("1234567890", endPos);

                // key = std::regex_replace(key, std::regex("[\\r\\n\\s]+"), ""); // remove newline characte and spaces
            }

            inputArrays.push_back(oneRow);
        }
    }
    return;
}

int extrapolateNextValue(const std::vector<int> &oneArray)
{

    int N = oneArray.size();
    std::vector<std::vector<int>> allDifferences;
    allDifferences.push_back(oneArray);
    bool allZero = false;

    int index =0;

    while (!allZero && N > 1)
    {
        std::vector<int> differences(N);
        std::adjacent_difference(allDifferences[index].begin(), allDifferences[index].end(), differences.begin()); // y0=x0, y1= x1- x0
        differences.erase(differences.begin());                                                  // removes first element

        // check if all values 0
        allZero = std::all_of(differences.begin(), differences.end(), [](const int element)
                              { return element == 0; });
        N = differences.size();
        allDifferences.push_back(differences);

        index += 1;
    }

    // for (int i=0; i<allDifferences.size(); i++){
    //         for (int j=0; j< allDifferences[i].size(); j++){
    //         std::cout<<allDifferences[i][j] <<", ";
    //     }
    //     std::cout<<std::endl;
    // }

    int interpolatedElement = 0; // allDifferences.back().back();

    for (int i = allDifferences.size() - 1; i > 0; i--)
    {

        interpolatedElement = allDifferences[i - 1].back() + interpolatedElement;
    }

    return interpolatedElement;
}

int getSum(std::string file_path)
{
    std::vector<std::vector<int>> inputArray;
    readInput(file_path, inputArray);
    std::cout << std::endl;
    int sum = 0;
    for (int i = 0; i < inputArray.size(); i++)
    {
        int value = extrapolateNextValue(inputArray[i]);
       
        sum += value;
    }

    return sum;
}