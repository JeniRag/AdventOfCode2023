#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>       //for summing ab vector
#include <bits/stdc++.h> //to find maximum of vector

/**
 * @brief Checks which games were possible and returns the sum of the corresponding IDs.
 *
 * @param file_path  directory of input path
 * @param colors the requirement conditions, stating which color must have how many cubes
 * @return ** int the sum of the ID's
 */
int PossibleGames(std::string file_path, std::map<std::string, int> colors) // input a dictionary
{
    std::fstream inputFile;
    inputFile.open(file_path, std::ios::in);

    // return error if it can't be opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 0;
    }

    // To save key and value of dict in seperate list
    std::vector<std::string> key;
    std::vector<int> possibleGames;

    // extract key, values and store in list
    for (std::map<std::string, int>::iterator it = colors.begin(); it != colors.end(); ++it)
    {
        key.push_back(it->first);
    }

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {

            bool possible = true; // assume every game is possible at first
            auto pos = line.find("Game");

            if (pos != std::string::npos)
            {
                // extract Game ID
                auto intPos = line.find_first_of("0123456789", pos + 4);
                int ID;
                if (intPos != std::string::npos)
                {

                    std::string intString = line.substr(intPos);
                    ID = std::stoi(intString); // convert ID string to integer
                }

                // iteratre over the colors stated in the requirement
                std::vector<std::string>::iterator iter = key.begin();

                for (iter; iter < key.end(); iter++)
                {

                    auto colorPos = line.find(*iter);

                    while (colorPos != std::string::npos)
                    {

                        // Update the starting position for the next search
                        auto noPos = line.find_first_of("0123456789", colorPos - 3); // position of number
                        if (noPos != std::string::npos)
                        {

                            int amount = std::stoi(line.substr(noPos));

                            // if already one color is already above the limit, the game won't work.
                            if (amount > colors.find(*iter)->second)
                            {
                                possible = false; // game won't work

                                break;
                            }
                        }
                        colorPos = line.find(*iter, colorPos + 1);
                    }
                }

                // if the gape is possible, save it's ID in the vector
                if (possible == true)
                {
                    possibleGames.push_back(ID);
                }
            }
        }
    }

    inputFile.close();
    int sumID;
    sumID = accumulate(possibleGames.begin(), possibleGames.end(), 0);

    return sumID;
}

/**
 * @brief Calculates the power of a set of cube and adds all of them up
 *
 * @param file_path directory to input file
 * @param colors the requirement conditions, stating which color must have how many cubes
 * @return ** int returns the sum of the powers
 */
int FewestNumberOfCubes(std::string file_path, std::vector<std::string> colors) // input a dictionary
{
    std::fstream inputFile;
    inputFile.open(file_path, std::ios::in);

    // return error if it can't be opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 0;
    }

    // to save the products of each game
    std::vector<int> products;

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {

            // initiate value
            int product = 1;

            auto pos = line.find("Game");
            std::vector<std::string>::iterator iter = colors.begin();
            for (iter; iter < colors.end(); iter++)
            {
                std::vector<int> amounts;
                auto colorPos = line.find(*iter);

                while (colorPos != std::string::npos)
                {

                    auto noPos = line.find_first_of("0123456789", colorPos - 3); // position of number
                    if (noPos != std::string::npos)
                    {

                        int amount = std::stoi(line.substr(noPos));
                        amounts.push_back(amount);
                    }
                    colorPos = line.find(*iter, colorPos + 1);
                }

                int minimum = *max_element(amounts.begin(), amounts.end());

                product *= minimum;
            }
            products.push_back(product);
        }
    }

    inputFile.close();
    int sum;
    sum = accumulate(products.begin(), products.end(), 0);

    return sum;
}