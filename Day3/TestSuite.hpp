#include <iostream>
#include <cxxtest/TestSuite.h>
#include "Functions.hpp"
#include <map>

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestGondelEngines(void)
    {
        int output;
                int expected = 4361;
        std::string example_file = "./data/example1.txt";

        output =GondolaEnginesSum(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }

 void TestGondelEnginesMyExample1(void)
    {
        int output;
                int expected = 32;
        std::string example_file = "./data/my_example1.txt";

        output =GondolaEnginesSum(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }

 void TestSumStarDigits(void)
    {
        int output;
                int expected = 467835;
        std::string example_file = "./data/example2.txt";

        output =SumStarDigits(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }


 void TestGondelEnginesMyExample2(void)
    {
        int output;
                int expected = 668;
        std::string example_file = "./data/my_example2.txt";

        output =SumStarDigits(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }



};