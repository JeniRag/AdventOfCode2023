#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include "Functions.hpp"
#include <cassert>

// Function definitions/ implementations

/**
* @brief For each line of the input file, builds the digit and returns the sum of it all.
*
* @param file_path directory path to the input file
* @return the sum of all the extracted digits.

**/

int Trebuchet(std::string file_path)
{
    std::fstream inputFile;
    int sum = 0;

    // open file
    inputFile.open(file_path, std::ios::in);

    // if file can't be opened pring an error
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 0;
    }

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            std::vector<int> integers; // To store extracted integers
            int extractedNumber;

            std::string currentNumber;
            // iterate over each character
            for (char character : line)
            {
                if (isdigit(character))
                { // if current character is a digit
                    currentNumber = character;
                    integers.push_back(std::stoi(currentNumber)); // push digit to vector
                }
            }

            assert(integers.size() > 0); // check that each line contained integers

            int first_digit, last_digit;
            first_digit = integers[0];

            if (integers.size() == 1)
            { // only one integer
                last_digit = integers[0];
            }
            else
            {
                last_digit = integers.back(); // last element of vector
            }

            extractedNumber = first_digit * 10 + last_digit;

            sum += extractedNumber;
            extractedNumber = 0;
        }
    }

    inputFile.close();

    return sum;
}

/**
 * @brief Extracts the number and consideres also digit, which are written in letters. Then it returns the sum of the extracted values.
 *
 * @param file_path directory of the input file
 * @return ** int the sum of the extracted values
 */

int ReadStringAsInt(std::string file_path)
{
    // Define dictionary of string and integer
    std::map<std::string, int> str_to_int = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    // To save key and value of dict in seperate list
    std::vector<std::string> key;

    // extract key, values and store in list
    for (std::map<std::string, int>::iterator it = str_to_int.begin(); it != str_to_int.end(); ++it)
    {
        key.push_back(it->first);
    }

    std::fstream inputFile;

    // initiate sum
    int sum = 0;

    // open file
    inputFile.open(file_path, std::ios::in);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 0;
    }

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;

        // iterate over each line
        while (getline(inputFile, line))
        {
            std::vector<int> integers; // To store extracted integers
            std::map<int, int> index_and_integers;

            int extractedNumber;

            // run for loop from 0 to end of vector
            std::vector<std::string>::iterator iter = key.begin();
            for (iter; iter < key.end(); iter++)
            {
                // access value in the memory to which the pointer
                // is referencing with *iter
                int currentNumber;
                auto pos = line.find(*iter); // returns only the first occurence

                while (pos != std::string::npos)
                {
                    
                    currentNumber = str_to_int.find(*iter)->second; // access to value by using key

                    index_and_integers.insert({pos, currentNumber});

                    // Update the starting position for the next search

                    pos = line.find(*iter, pos + 1);
                }
            }

            std::string currentNumber;
            int index_int = 0;
            for (char character : line)
            {

                if (isdigit(character))
                {
                    currentNumber = character;
                    index_and_integers.insert({index_int, std::stoi(currentNumber)});
                }
                index_int += 1;
            }

            // map sorts already it key value pairs based on the order of keys
            for (std::map<int, int>::iterator it = index_and_integers.begin(); it != index_and_integers.end(); ++it)
            {
                //  std::cout <<"index: "<<it->first << ", value: "<< it->second<<std::endl;
                integers.push_back(it->second);
            }

            int first_digit, last_digit;
            first_digit = integers[0];

            if (integers.size() == 1)
            { // only one integer
                last_digit = integers[0];
            }
            else
            {
                last_digit = integers.back(); // last element of vector
            }

            extractedNumber = first_digit * 10 + last_digit;

            sum += extractedNumber;
        }
    }

    inputFile.close();

    return sum;
}