#include <iostream>
#include <cxxtest/TestSuite.h>
#include "Functions.hpp"

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestTrebuchet(void)
    {
        int output;
        int expected = 142;
        std::string example_file = "./data/example_1.txt";

        output = Trebuchet(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }

    void TestReadStringAsInteger(void)
    {
        int output;
        int expected = 281;
        std::string example_file = "./data/example_2.txt";

        output = ReadStringAsInt(example_file);
        TS_ASSERT_EQUALS(output, expected);
    }

     void TestMyExample1(void)
    {

        
        int output;
        int output2; 
        int expected = 204; //46 + 57 + 56 + 45
        int expected2 = 157; //17 + 58 + 54 + 28;
        std::string example_file = "./data/my_example_1.txt";

        output = Trebuchet(example_file);
        output2 = ReadStringAsInt(example_file);
        TS_ASSERT_EQUALS(output, expected);
        TS_ASSERT_EQUALS(output2, expected2);
    }
};