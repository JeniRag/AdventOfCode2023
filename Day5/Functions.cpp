#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <cassert>
#include <numeric>       //for summing ab vector
#include <bits/stdc++.h> //to find maximum of vector
#include <regex>
#include "AlmanacList.hpp"
#include "Category.hpp"



/*
Reads input file and fills the AlamancList class with the input information.
    - file_path: string indicating the input file
    - &aList: reference to a class aList.
*/
void ReadInput(std::string file_path, AlmanacList& aList)
{

    std::fstream inputFile;

    // open file
    inputFile.open(file_path, std::ios::in);

    // strings to find
    std::string seedExpression = "seeds: ";
    std::string seedToSoilExpression = "seed-to-soil map:";
    std::string soilToFertilizerExpression = "soil-to-fertilizer map:";
    std::string fertilizerToWaterExpression = "fertilizer-to-water map:";
    std::string waterToLightExpression = "water-to-light map:";
    std::string lightToTemperatureExpression = "light-to-temperature map:";
    std::string temperatureToHumidityExpression = "temperature-to-humidity map:";
    std::string humidityToLocationExpression = "humidity-to-location map:";

    // vectors to store input
    std::vector<int64_t> seeds;
    std::vector<std::vector<int64_t>> seedToSoil, soilToFertilizer, fertilizerToWater, waterToLight, lightToTemperature, temperatureToHumidity, humidityToLocation;

    Category currentCategory = Seed;

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
            // extract the seed numbers
            auto seedPos = line.find(seedExpression);
            if (seedPos != std::string::npos)
            {
                auto intPos = line.find_first_of("0123456789", 0); // find first integer in seed line

                while (intPos != std::string::npos)
                {
                    auto intEndPos = line.find_first_not_of("0123456789", intPos);

                    std::string seedNumberString = line.substr(intPos, intEndPos - intPos); // extract int
                    seedNumberString = std::regex_replace(seedNumberString, std::regex("\\r\\n|\\r|\\n"), "");
                    
                    int64_t seedNumber = std::stol(seedNumberString); // convert string to integer
                    seeds.push_back(seedNumber);                  // store see Number in vector

                    intPos = line.find_first_of("0123456789", intEndPos);
                    
                }
            }

            // define which category it is reading
            if (line.find(seedToSoilExpression) != std::string::npos)
            {
                currentCategory = SeedToSoil;
                continue;
            }
            else if (line.find(soilToFertilizerExpression) != std::string::npos)
            {
                currentCategory = SoilToFertilizer;
                continue;
            }
            else if (line.find(fertilizerToWaterExpression) != std::string::npos)
            {
                currentCategory = FertilizerToWater;
                continue;
            }
            else if (line.find(waterToLightExpression) != std::string::npos)
            {
                currentCategory = WaterToLight;
                continue;
            }
            else if (line.find(lightToTemperatureExpression) != std::string::npos)
            {
                currentCategory = LightToTemperature;
                continue;
            }
            else if (line.find(temperatureToHumidityExpression) != std::string::npos)
            {
                currentCategory = TemperatureToHumidity;
                continue;
            }
            else if (line.find(humidityToLocationExpression) != std::string::npos)
            {
                currentCategory = HumidityToLocation;
                continue;
            }

            std::vector<int64_t> row;

            if (currentCategory != Seed)
            {

                // exctract row numbers into vector
                auto digitPos = line.find_first_of("0123456789", 0);
                while (digitPos != std::string::npos)
                {
                    auto digitEndPos = line.find_first_not_of("0123456789", digitPos);
                    std::string digitString = line.substr(digitPos, digitEndPos - digitPos);
                    digitString = std::regex_replace(digitString, std::regex("\\r\\n|\\r|\\n"), "");
                    int64_t digit = std::stol(digitString);

                    row.push_back(digit);

                    digitPos = line.find_first_of("0123456789", digitEndPos);
                }
            }

            // push numbers to correct category vector
            if (row.size() > 0)
            {

                switch (currentCategory)
                {

                case SeedToSoil:
                    seedToSoil.push_back(row);
                    break;
                case SoilToFertilizer:
                    soilToFertilizer.push_back(row);
                    break;
                case FertilizerToWater:
                    fertilizerToWater.push_back(row);
                    break;
                case WaterToLight:
                    waterToLight.push_back(row);
                    break;
                case LightToTemperature:
                    lightToTemperature.push_back(row);
                    break;
                case TemperatureToHumidity:
                    temperatureToHumidity.push_back(row);
                    break;
                case HumidityToLocation:
                    humidityToLocation.push_back(row);
                    break;
                }
            }
          
        }
    }

    inputFile.close();

    // AlmanacList aList;
    aList.setSeeds(seeds);
    aList.setSTS(seedToSoil);
    aList.setSTF(soilToFertilizer);
    aList.setFTW(fertilizerToWater);
    aList.setWTL(waterToLight);
    aList.setLTT(lightToTemperature);
    aList.setTTH(temperatureToHumidity);
    aList.setHTL(humidityToLocation);
}


/*
Reads input file and searches for the lowest location number after mapping the seeds.
*/
int64_t FindLowestLocation(std::string file_path)
{

    AlmanacList aList; //empty class

    ReadInput(file_path, aList); //fills class with the input values

    return aList.getLowestLocationNumber();
}

int64_t FindLowestLocationFromRanges(std::string file_path){
    AlmanacList aList; //empty class

    ReadInput(file_path, aList); //fills class with the input values

    return aList.getLowestLocationNumberFromSeedRanges();
}
