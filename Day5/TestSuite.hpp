#include <iostream>
#include <cxxtest/TestSuite.h>
#include "Functions.hpp"
#include "AlmanacList.hpp"
#include <map>

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestReadInput(void)
    {

        std::vector<std::vector<int64_t>> expected{
            {50, 98, 2},
            {52, 50, 48}};
        std::string example_file = "./data/example1.txt";

        AlmanacList aList;
        ReadInput(example_file, aList);

        TS_ASSERT_EQUALS(aList.mSeedToSoil.size(), expected.size());
        TS_ASSERT_EQUALS(aList.mSeedToSoil[0].size(), expected[0].size());

        for (int i = 0; i < expected.size(); i++)
        {
            std::cout << "-------" << std::endl;
            for (int j = 0; j < expected[0].size(); j++)
            {
                TS_ASSERT_EQUALS(aList.mSeedToSoil[i][j], expected[i][j]);
            }
        }
    }

    void TesFertilizerMapp(void)
    {

        std::vector<std::vector<int64_t>> expected{
            {49, 53, 8},
            {0, 11, 42},
            {42, 0, 7},
            {57, 7, 4}};
        std::string example_file = "./data/example1.txt";

        AlmanacList aList;
        ReadInput(example_file, aList);

        TS_ASSERT_EQUALS(aList.mFertilizerToWater.size(), expected.size());
        TS_ASSERT_EQUALS(aList.mFertilizerToWater[0].size(), expected[0].size());

        for (int i = 0; i < expected.size(); i++)
        {
            std::cout << "-------" << std::endl;
            for (int j = 0; j < expected[0].size(); j++)
            {
                TS_ASSERT_EQUALS(aList.mFertilizerToWater[i][j], expected[i][j]);
            }
        }
    }

    void TestMap(void)
    {
        int64_t output, output2;
        int64_t expected = 81;
        int64_t expected2= 84;
        std::string example_file = "./data/example1.txt";

        AlmanacList aList;

        ReadInput(example_file, aList);
        output = aList.map(79, SeedToSoil);
        TS_ASSERT_EQUALS(output, expected);
        
        output2 = aList.map(82, SeedToSoil);
        TS_ASSERT_EQUALS(output2, expected2);


    }
    void TestGetLocation(void)
    {
        std::vector<int64_t> inputs {79, 14, 82};
        std::vector<int64_t> expected {82, 43, 46};
        //      std::vector<int64_t> inputs { 82};
        // std::vector<int64_t> expected { 46};
        
        std::string example_file = "./data/example1.txt";

        AlmanacList aList;

        ReadInput(example_file, aList);

        for (int i=0; i<inputs.size(); i++){

            int output = aList.getLocation(inputs[i]);
            TS_ASSERT_EQUALS(output, expected[i]);
        }
       

    }
    // void TestFindLowestLocation(void)
    // {
    //     int output;
    //     int expected = 35;
    //     std::string example_file = "./data/example1.txt";

    //     output = FindLowestLocation(example_file);
    //     TS_ASSERT_EQUALS(output, expected);
    // }

    // void TestFindLowestLocationFromRanges(void)
    // {
    //     int output;
    //     int expected = 46;
    //     std::string example_file = "./data/example1.txt";

    //     output = FindLowestLocationFromRanges(example_file);
    //     TS_ASSERT_EQUALS(output, expected);
    // }
};