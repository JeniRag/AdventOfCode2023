#include <iostream>
#include <cxxtest/TestSuite.h>
#include "Functions.hpp"
#include "Race.hpp"
#include <map>

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestCalculateProduct(void)
    {

        long expected = 288;
        long output;

        std::string example_file = "./data/example1.txt";

        
        output = calculateProduct(example_file);

        TS_ASSERT_EQUALS(expected, output);


 
    }

    void TestCombineInput(void){

        int expected = 71503;
        int output; 
         std::string example_file = "./data/example1.txt";

        

        output = combineInputAndGetProduct(example_file);
 TS_ASSERT_EQUALS(expected, output);

    }

};