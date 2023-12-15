#include <iostream>
#include <cxxtest/TestSuite.h>
#include "Functions.hpp"
#include <map>

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestGetPointsOfScratchcard(void)
    {
        int output;
                int expected = 13;
        std::string example_file = "./data/example1.txt";

        output =GetPointsOfSratchcard(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }

    void TestGetNumberOfCopies(void)
    {
        int output;
                int expected = 30;
        std::string example_file = "./data/example1.txt";

        output =GetNumberOfCopies(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }

     void TestGetNumberOfCopiesMyExample(void)
    {
        int output;
                int expected = 3;
        std::string example_file = "./data/my_example2.txt";

        output =GetNumberOfCopies(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }




};