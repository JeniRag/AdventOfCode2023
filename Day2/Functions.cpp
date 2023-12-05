#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>
#include <bits/stdc++.h> 

int PossibleGames(std::string file_path, std::map<std::string, int> colors) // input a dictionary
{
    std::fstream inputFile;
    inputFile.open(file_path, std::ios::in);

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
           // std::cout<<"--------"<<std::endl;
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
                    // std::cout << "integer " << ID << std::endl;
                }

               // std::cout <<"Game "<<ID<<std::endl;

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
                           // std::cout << "adding "<<*iter<< " "<<std::stoi( line.substr(noPos))<<std::endl;
                            int amount = std::stoi( line.substr(noPos));

                            // if already one color is already above the limit, the game won't work.
                            if (amount > colors.find(*iter)->second)
                            {
                                possible = false; // game won't work
                                //std::cout<<"not fulfilled"<<std::endl;
                                break;
                            }

                        }
                        colorPos = line.find(*iter, colorPos + 1);
                    }
                    
                }

                if (possible==true){
                    possibleGames.push_back(ID);
                   // std::cout<<"fulfilled"<<std::endl;
                }
            }
        }
    }

    inputFile.close();
    int sumID;
    sumID = accumulate(possibleGames.begin(), possibleGames.end(), 0);

    return sumID;
}


int FewestNumberOfCubes(std::string file_path, std::vector<std::string> colors) // input a dictionary
{
    std::fstream inputFile;
    inputFile.open(file_path, std::ios::in);
    std::vector<int> products;

    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            std::cout<<"--------"<<std::endl;
            std::vector<int> minimumColors;
            int product = 1;
            
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
                    // std::cout << "integer " << ID << std::endl;
                }

                std::cout <<"Game "<<ID<<std::endl;

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
                           // std::cout << "adding "<<*iter<< " "<<std::stoi( line.substr(noPos))<<std::endl;
                            int amount = std::stoi( line.substr(noPos));
                            amounts.push_back(amount);

                            // if already one color is already above the limit, the game won't work.
                        
                        }
                        colorPos = line.find(*iter, colorPos + 1);
                    }

                    int minimum = *max_element(amounts.begin(), amounts.end());
                    std::cout<<"Minimum of "<<*iter<< ": "<< minimum <<std::endl;
                    product *= minimum;
                    
                }
                products.push_back(product);


               
            }

            
        }
    }

    inputFile.close();
    int sum;
    sum = accumulate(products.begin(),products.end(), 0);
   
    return sum ;
}