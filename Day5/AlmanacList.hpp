#ifndef ALMANACLISTHEADERDEF
#define ALMANACLISTHEADERDEF
#include <iostream>
#include <vector>
#include <map>
#include "Category.hpp"

class AlmanacList
{

private:
    std::vector<int64_t> mSeeds;
    std::vector<int64_t> mSeedsRanges; //for task 2
    std::vector<std::vector<int64_t>> mSeedToSoil, mSoilToFertilizer, mFertilizerToWater, mWaterToLight, mLightToTemperature, mTemperatureToHumidity, mHumidityToLocation;
    void getSeedRanges();

public:
    friend class MyTestSuite;
    AlmanacList(); // constructor

    // Setters
    void setSeeds(std::vector<int64_t> seeds);
    void setSTS(std::vector<std::vector<int64_t>> arrays);
    void setSTF(std::vector<std::vector<int64_t>> arrays);
    void setFTW(std::vector<std::vector<int64_t>> arrays);
    void setWTL(std::vector<std::vector<int64_t>> arrays);
    void setLTT(std::vector<std::vector<int64_t>> arrays);
    void setTTH(std::vector<std::vector<int64_t>> arrays);
    void setHTL(std::vector<std::vector<int64_t>> arrays);

    // Methods
    int64_t map(int64_t input, Category currentCategory);
    int64_t mapNoForLoop(int64_t input, Category currentCategory);
    int64_t getLocation(int64_t input);

    int64_t getLowestLocationNumber();
    int64_t getLowestLocationNumberFromSeedRanges();

    int64_t getLocationNoForLoop(int64_t input)


    

};

#endif