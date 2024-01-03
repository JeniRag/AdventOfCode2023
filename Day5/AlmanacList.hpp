#ifndef ALMANACLISTHEADERDEF
#define ALMANACLISTHEADERDEF
#include <iostream>
#include <vector>
#include <map>
#include "Category.hpp"

class AlmanacList
{

private:
    std::vector<long> mSeeds;
    std::vector<std::vector<long>> mSeedToSoil, mSoilToFertilizer, mFertilizerToWater, mWaterToLight, mLightToTemperature, mTemperatureToHumidity, mHumidityToLocation;

public:
    friend class MyTestSuite;
    AlmanacList(); // constructor

    // Setters
    void setSeeds(std::vector<long> seeds);
    void setSTS(std::vector<std::vector<long>> arrays);
    void setSTF(std::vector<std::vector<long>> arrays);
    void setFTW(std::vector<std::vector<long>> arrays);
    void setWTL(std::vector<std::vector<long>> arrays);
    void setLTT(std::vector<std::vector<long>> arrays);
    void setTTH(std::vector<std::vector<long>> arrays);
    void setHTL(std::vector<std::vector<long>> arrays);

    // MEthods
    long map(long input, Category currentCategory);
    long getLocation(long input);

    long getLowestLocationNumber();

};

#endif