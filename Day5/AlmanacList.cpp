#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>  // std::transform
#include <functional> // std::plus
#include <bits/stdc++.h> //to find maximum of vector
#include "AlmanacList.hpp"

#include "Category.hpp"

AlmanacList::AlmanacList()
{
}

void AlmanacList::setSeeds(std::vector<long> seeds)
{
    assert(seeds.size()>0);
    mSeeds = seeds;
}

void AlmanacList::setSTS(std::vector<std::vector<long>> arrays)
{
    assert(arrays.size() >0);
    mSeedToSoil = arrays;
}
void AlmanacList::setSTF(std::vector<std::vector<long>> arrays)
{
     assert(arrays.size() >0);
    mSoilToFertilizer = arrays;
}

void AlmanacList::setFTW(std::vector<std::vector<long>> arrays)
{
     assert(arrays.size() >0);
    mFertilizerToWater = arrays;
}
void AlmanacList::setWTL(std::vector<std::vector<long>> arrays)
{
     assert(arrays.size() >0);
    mWaterToLight = arrays;
}
void AlmanacList::setLTT(std::vector<std::vector<long>> arrays)
{
     assert(arrays.size() >0);
    mLightToTemperature = arrays;
}
void AlmanacList::setTTH(std::vector<std::vector<long>> arrays)
{
     assert(arrays.size() >0);
    mTemperatureToHumidity = arrays;
}
void AlmanacList::setHTL(std::vector<std::vector<long>> arrays)
{
     assert(arrays.size() >0);
    mHumidityToLocation = arrays;
}


/*
Given the input digit and the category, return the corresponding output value
*/
long AlmanacList::map(long input, Category currentCategory)
{

    std::vector<std::vector<long>> mapVector;
    long output;

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
        std::cout<<"Category not found"<<std::endl;

    }


    output = input; // if input can be mapped, it will be overriden in the for loop. Else it corresponds to the input value.
    for (int i = 0; i < mapVector.size(); i++)
    {

        long destinationStart = mapVector[i][0];
        
        long sourceStart = mapVector[i][1];
        long values = mapVector[i][2];

        if ((input >= sourceStart) && (input <= sourceStart + values))
        {
            long difference = input - sourceStart;
            output = destinationStart + difference; //output is overriden
            break;
        }
    }

    return output;
}


long AlmanacList::getLocation(long input){
    long output;

    std::vector<Category> CategoryList     {

        SeedToSoil,
        SoilToFertilizer,
        FertilizerToWater,
        WaterToLight,
        LightToTemperature,
        TemperatureToHumidity,
        HumidityToLocation
    };
   
    for (int i = 0; i< CategoryList.size(); i++){
        

        output = map(input, CategoryList[i]);
       
        input = output;
    }

    return output;


}

long AlmanacList::getLowestLocationNumber(){
    

    std::vector<long> locations;

    for (int i=0; i<mSeeds.size(); i++){
       long loc = getLocation(mSeeds[i]);

        
        locations.push_back(loc);

    }

    assert(locations.size() > 0);

 return *min_element(locations.begin(), locations.end());
}
