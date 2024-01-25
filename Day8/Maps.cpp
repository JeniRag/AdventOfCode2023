#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>  // std::transform
#include <functional> // std::plus
#include "Maps.hpp"

Maps::Maps(std::string directions, std::map<std::string, std::vector<std::string>> dictionary)
{
    mDirections = directions;
    mDictionary = dictionary;
}

/**
 * @brief returns the number of steps needed to reach the destinatino
 * 
 * @param start string that contains the starting node
 * @param destination string that contains the destination node
 * @return ** int 
 */
int Maps::followMap(std::string start, std::string destination)
{

    int index = 0;
    int directionIndex;
    int steps = 0;
    std::string currentLocation = start;

    while (currentLocation != destination)
    {
        // std::cout<<"currentLocation: "<<currentLocation<<std::endl; 
        directionIndex = index % mDirections.size();

        auto location = mDictionary.find(currentLocation);

        if (location == mDictionary.end()){
            std::cerr<< "Location not " << currentLocation <<" in dictionary"<<std::endl;
        }


        char direction = mDirections[directionIndex];

        if (direction == 'R')
        {
            currentLocation = location->second[1]; // right side
        }
        else if (direction == 'L')
        {
            currentLocation = location->second[0]; // left side
        }
        else
        {
            std::cerr << "Given direction " << direction << " not known" << std::endl;
        }

        steps += 1;
        index += 1;

        // std::cout<<"current steps: "<<steps<<std::endl;
    }

    return steps;
}
