#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
            auto intPos = line.find_first_of("-1234567890", 0); // make sure it also reads the minus sign

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

/**
 * @brief checks if all elements of an array are the same
 *
 * @param vec
 * @return true
 * @return false
 */
bool allElementsSame(const std::vector<long> &vec)
{
    auto it = std::adjacent_find(vec.begin(), vec.end(), std::not_equal_to<int>());
    return it == vec.end();
}

/**
 * @brief Calculates the difference between the next element in an array. Takes the difference as a new array and repeats until all elements in the array are the same.
 * 
 * @param oneArray input array
 * @param allDifferences matrix to store all the difference arrays.
 * @return ** void 
 */

void calculateDifferences(const std::vector<long> &oneArray, std::vector<std::vector<long>> &allDifferences)
{

    int N = oneArray.size(); // size of Array
    allDifferences.push_back(oneArray); // put the input array in it

    bool allElementsEqual = false; // start with false

    while (!allElementsEqual)
    {
        assert(N > 1);

        std::vector<long> differences(N);                                                                          // initiate array to store the differences
        std::adjacent_difference(allDifferences.back().begin(), allDifferences.back().end(), differences.begin()); // y0=x0, y1= x1- x0
        differences.erase(differences.begin());                                                                    // removes first element

        allDifferences.push_back(differences);

        // check if all values 0
        // allZero = std::all_of(differences.begin(), differences.end(), [](const long element)
        //                       { return element == 0; });

        allElementsEqual = allElementsSame(differences); // check if all elements are the same

        N = differences.size(); // calculate new size
    }
    return;
}

/**
 * @brief Extrapolates the last (right) value of an array. For Task 1.
 *
 * @param oneArray 1D array
 * @return ** long , the extrapolated value
 */
long extrapolateNextValue(const std::vector<long> &oneArray)
{
    std::vector<std::vector<long>> allDifferences;
    calculateDifferences(oneArray, allDifferences);

    long extrapolatedElement = allDifferences.back().back();

    for (int i = allDifferences.size() - 1; i > 0; i--)
    {

        extrapolatedElement = allDifferences[i - 1].back() + extrapolatedElement; // extrapolated the right element of one array up
    }

    return extrapolatedElement;
}

/**
 * @brief extrapolates the first value (left). For task 2.
 *
 * @param oneArray
 * @return ** long
 */
long extrapolateBack(const std::vector<long> &oneArray)
{ 
    std::vector<std::vector<long>> allDifferences;
    calculateDifferences(oneArray, allDifferences);

    long extrapolatedElement = allDifferences.back().front();

    for (int i = allDifferences.size() - 1; i > 0; i--)
    {

        extrapolatedElement = allDifferences[i - 1].front() - extrapolatedElement;
    }

    return extrapolatedElement;
}

/**
 * @brief Get the Sum object based on the selected extrapolation technique.
 * 
 * @param file_path 
 * @param extrapolate functionpointer that defines the extrapolation.
 * @return ** long 
 */
long getSum(std::string file_path, long (*extrapolate)(const std::vector<long> &oneArray))
{

    std::vector<std::vector<long>> inputArray;
    readInput(file_path, inputArray);

    std::cout << std::endl;

    long sum = 0;
    for (int i = 0; i < inputArray.size(); i++)
    {

        long value = extrapolate(inputArray[i]); 

        sum += value;
    }

    return sum;
}