#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include "Functions.hpp"

// Function definitions/ implementations

int Trebuchet(std::string file_path)
{
    std::fstream inputFile;
    int sum = 0;

    // open file
    inputFile.open(file_path, std::ios::in);

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            std::vector<int> integers; // To store extracted integers
            int a;

            std::string currentNumber;
            for (char character : line)
            {
                if (isdigit(character))
                { // if current character is a digit
                    currentNumber = character;
                    integers.push_back(std::stoi(currentNumber)); // push digit to vector
                }
            }

            if (integers.size() == 1)
            { // only one integer
                a = integers[0] * 10 + integers[0];
            }

            else if (integers.size() >= 2)
            {
                int x1 = integers[0];
                int x2 = integers.back(); // last element

                a = x1 * 10 + x2;
            }
            //  std::cout<<"a = "<< a<< std::endl;
            sum += a;
            a = 0;
        }
    }

    inputFile.close();

    return sum;
}

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
      //  std::cout<<"added to key list: "<<it -> first<<std::endl;
      
    }

    std::fstream inputFile;

    // initiate sum
    int sum = 0;

    // open file
    inputFile.open(file_path, std::ios::in);

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;

        // iterate over each line
        while (getline(inputFile, line))
        {
            std::vector<int> integers; // To store extracted integers
            std::map<int, int> index_and_integers;

            int a;

            // run for loop from 0 to end of vector
            std::vector<std::string>::iterator iter = key.begin();
            for (iter; iter < key.end(); iter++)
            {
                // access value in the memory to which the pointer
                // is referencing with *iter
               int currentNumber;
              auto pos = line.find(*iter); //returns only the first occurence

              
            while (pos != std::string::npos)
                {
                    std::cout<< "position of "<<*iter<< " is "<< pos <<std::endl;
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


            //map sorts already it key value pairs based on the order of keys
            for (std::map<int, int>::iterator it = index_and_integers.begin(); it != index_and_integers.end(); ++it)
            {
              //  std::cout <<"index: "<<it->first << ", value: "<< it->second<<std::endl;
                integers.push_back(it->second);
            }

            if (integers.size() == 1)
            { // only one integer
                a = integers[0] * 10 + integers[0];
            }

            else if (integers.size() >= 2)
            {
                int x1 = integers[0];
                int x2 = integers.back(); // last element

                a = x1 * 10 + x2;
            }

           std::cout << "a = "<<a <<std::endl;
            sum += a;
            //a = 0;

            std::cout <<"--------"<<std::endl;
        }
    }

    inputFile.close();

    return sum;
}