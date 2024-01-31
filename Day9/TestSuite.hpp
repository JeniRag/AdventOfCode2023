#include <iostream>
#include <cxxtest/TestSuite.h>
// #include <map>
#include "Functions.hpp"

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestReadInput(void)
    {

        std::string example_file = "./data/example1.txt";
        std::vector<std::vector<int>> expected = {{0, 3, 6, 9, 12, 15}, {1, 3, 6, 10, 15, 21}, {10, 13, 16, 21, 30, 45}};

        std::vector<std::vector<int>> inputArray;
        readInput(example_file, inputArray);

        TS_ASSERT_EQUALS(expected.size(), inputArray.size());

        for (int i = 0; i < expected.size(); i++)
        {
            for (int j = 0; j < expected[0].size(); j++)
            {
                TS_ASSERT_EQUALS(expected[i][j], inputArray[i][j]);
            }
        }
    }

    void TestExtrapolateNextValue(void){

        std::vector<int> oneArray = {0, 3, 6, 9, 12, 15};
        int expected = 18;
        int output = extrapolateNextValue(oneArray);

        TS_ASSERT_EQUALS(expected, output);


    }

    void TestTask1(void){
        std::string example_file = "./data/example1.txt";
        int expected= 114;
        int output = getSum(example_file);
        TS_ASSERT_EQUALS(expected, output);


    }
    
};