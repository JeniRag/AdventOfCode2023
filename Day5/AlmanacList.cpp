#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>     // std::transform
#include <functional>    // std::plus
#include <bits/stdc++.h> //to find maximum of vector
#include "AlmanacList.hpp"

#include "Category.hpp"

AlmanacList::AlmanacList()
{
}

void AlmanacList::setSeeds(std::vector<int64_t> seeds)
{
    assert(seeds.size() > 0);
    mSeeds = seeds;
    sort(mSeeds.begin(), mSeeds.end());
}


void AlmanacList::setSTS(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mSeedToSoil = arrays;
}
void AlmanacList::setSTF(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mSoilToFertilizer = arrays;
}

void AlmanacList::setFTW(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mFertilizerToWater = arrays;
}
void AlmanacList::setWTL(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mWaterToLight = arrays;
}
void AlmanacList::setLTT(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mLightToTemperature = arrays;
}
void AlmanacList::setTTH(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mTemperatureToHumidity = arrays;
}
void AlmanacList::setHTL(std::vector<std::vector<int64_t>> arrays)
{
    assert(arrays.size() > 0);
    mHumidityToLocation = arrays;
}

/*
Given the input digit and the category, return the corresponding output value
*/
int64_t AlmanacList::map(int64_t input, Category currentCategory)
{

    std::vector<std::vector<int64_t>> mapVector = mSeedToSoil; // reference to avoid copying
    int64_t output;

    // select the correct map
    switch (currentCategory)
    {
    case SeedToSoil:
        mapVector = mSeedToSoil;
        break;
    case SoilToFertilizer:
        mapVector = mSoilToFertilizer;
        break;
    case FertilizerToWater:
        mapVector = mFertilizerToWater;
        break;
    case WaterToLight:
        mapVector = mWaterToLight;
        break;
    case LightToTemperature:
        mapVector = mLightToTemperature;
        break;
    case TemperatureToHumidity:
        mapVector = mTemperatureToHumidity;
        break;
    case HumidityToLocation:
        mapVector = mHumidityToLocation;
        break;
    default:
        std::cout << "Category not found" << std::endl;
    }

    output = input; // if input can be mapped, it will be overriden in the for loop. Else it corresponds to the input value.
    for (int i = 0; i < mapVector.size(); i++)
    {

        int64_t destinationStart = mapVector[i][0];

        int64_t sourceStart = mapVector[i][1];

        int64_t values = mapVector[i][2];

        if ((input >= sourceStart) && (input <= sourceStart + values))
        {
            int64_t difference = input - sourceStart;
            // std::cout<<" (" << input << "-" << sourceStart <<" = "<<difference << ") ";
            output = destinationStart + difference; // output is overriden

            break;
        }
    }

    return output;
}

int64_t AlmanacList::mapNoForLoop(std::vector<int64_t> input, Category currentCategory)
{

    std::vector<std::vector<int64_t>> mapVector = mSeedToSoil; // reference to avoid copying
    int64_t output;

    // select the correct map
    switch (currentCategory)
    {
    case SeedToSoil:
        mapVector = mSeedToSoil;
        break;
    case SoilToFertilizer:
        mapVector = mSoilToFertilizer;
        break;
    case FertilizerToWater:
        mapVector = mFertilizerToWater;
        break;
    case WaterToLight:
        mapVector = mWaterToLight;
        break;
    case LightToTemperature:
        mapVector = mLightToTemperature;
        break;
    case TemperatureToHumidity:
        mapVector = mTemperatureToHumidity;
        break;
    case HumidityToLocation:
        mapVector = mHumidityToLocation;
        break;
    default:
        std::cout << "Category not found" << std::endl;
    }

    output = input; // if input can be mapped, it will be overriden in the for loop. Else it corresponds to the input value.
    for (int i = 0; i < mapVector.size(); i++)
    {

        int64_t destinationStart = mapVector[i][0];

        int64_t sourceStart = mapVector[i][1];

        int64_t values = mapVector[i][2];

        if ((input >= sourceStart) && (input <= sourceStart + values))
        {
            int64_t difference = input - sourceStart;
            // std::cout<<" (" << input << "-" << sourceStart <<" = "<<difference << ") ";
            output = destinationStart + difference; // output is overriden

            break;
        }
    }

    return output;
}

/*
Returns for a given input (seed number) the corresponding location number.
*/

int64_t AlmanacList::getLocation(int64_t input)
{
    int64_t output;

    std::vector<Category> CategoryList{
        SeedToSoil,
        SoilToFertilizer,
        FertilizerToWater,
        WaterToLight,
        LightToTemperature,
        TemperatureToHumidity,
        HumidityToLocation};
    // std::cout<<input<<" ";

    for (int i = 0; i < CategoryList.size(); i++)
    {

        output = map(input, CategoryList[i]);

        input = output;
        // std::cout<<"-->"<<output<<" ";
    }
    // std::cout<<std::endl;

    return output;
}


int64_t AlmanacList::getLocationNoForLoop(int64_t input)
{
    int64_t output;

    std::vector<Category> CategoryList{
        SeedToSoil,
        SoilToFertilizer,
        FertilizerToWater,
        WaterToLight,
        LightToTemperature,
        TemperatureToHumidity,
        HumidityToLocation};
    



    // for (int i = 0; i < CategoryList.size(); i++)
    // {

    //     output = map(input, CategoryList[i]);

    //     input = output;
    //     // std::cout<<"-->"<<output<<" ";
    // }
    // std::cout<<std::endl;

    return output;
}


/*
Returns the smallest location number
*/

int64_t AlmanacList::getLowestLocationNumber()
{

    std::vector<int64_t> locations;

    for (int i = 0; i < mSeeds.size(); i++)
    {
        int64_t loc = getLocation(mSeeds[i]);

        locations.push_back(loc);
    }

    assert(locations.size() > 0);

    return *min_element(locations.begin(), locations.end());
}

int64_t AlmanacList::getLowestLocationNumberFromSeedRanges()
{

    assert(mSeeds.size() > 0);
    std::vector<int64_t> locations;

    for (int i = 0; i < mSeeds.size(); i += 2)
    {
        std::cout << "Index: " << i << std::endl;
        int64_t length = mSeeds[i + 1];

        for (int64_t s = mSeeds[i]; s < mSeeds[i] + length; s++)
        {
            int64_t loc = getLocation(s);

            locations.push_back(loc);

            // std::cout << loc << std::endl;
        }
    }

    // assert(locations.size() > 0);

    return *min_element(locations.begin(), locations.end());
    // return 0;
}