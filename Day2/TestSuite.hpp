#include <iostream>
#include <cxxtest/TestSuite.h>
#include "Functions.hpp"
#include <map>

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestPossibleGames(void)
    {
        int output;
std::map<std::string, int> colors= {{"red", 12}, {"green", 13}, {"blue", 14}};
        int expected = 8;
        std::string example_file = "./data/example_1.txt";

        output = PossibleGames(example_file, colors);
        TS_ASSERT_EQUALS(output, expected);
    }

 void TestFewestNumberOfCubes(void)
    {
        int output;
        std::vector<std::string> colors= {"red", "green", "blue"};
                int expected = 2286;
                std::string example_file = "./data/example_1.txt";

                output = FewestNumberOfCubes(example_file, colors);
                TS_ASSERT_EQUALS(output, expected);
    }


};