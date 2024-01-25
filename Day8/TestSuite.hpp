#include <iostream>
#include <cxxtest/TestSuite.h>
// #include <map>
#include "Functions.hpp"
#include "Maps.hpp"

class MyTestSuite : public CxxTest::TestSuite
{

public:
    void TestReadInput(void)
    {

        std::string example_file = "./data/example1.txt";

        std::string directions;
        std::map<std::string, std::vector<std::string>> dictionary;
        readInput(example_file, directions, dictionary);

        std::cout << "\n Direction: " << directions << std::endl;

        TS_ASSERT(directions == "LLR"); // check if direction is read

        for (auto it = dictionary.begin(); it != dictionary.end(); it++)
        {
            std::cout << it->first << " = (" << it->second[0] << ", " << it->second[1] << ")" << std::endl;
        }
    }

    void TestMaps(void)
    {
        int output, expected;
      

        std::string start = "AAA";
        std::string destination = "ZZZ";
        
        std::string example_file = "./data/example1.txt";


        std::string directions;
        std::map<std::string, std::vector<std::string>> dictionary;

        readInput(example_file, directions, dictionary);
        Maps graph(directions, dictionary);

        std::cout<<"\n Dictionary: \n";
        for (auto it = graph.mDictionary.begin(); it != graph.mDictionary.end(); it++)
        {
            std::cout << it->first << "= (" << it->second[0] << ", " << it->second[1] << ")" << std::endl;
        }

        auto location = graph.mDictionary.find("AAA");

        TS_ASSERT(location != graph.mDictionary.end());
    }
    void TestMapsFollow(void)
    {
        int output, expected;
        expected = 6;

        std::string start = "AAA";
        std::string destination = "ZZZ";
        
        std::string example_file = "./data/example1.txt";


        std::string directions;
        std::map<std::string, std::vector<std::string>> dictionary;

        readInput(example_file, directions, dictionary);
        Maps graph(directions, dictionary);
        output = graph.followMap(start, destination);

        TS_ASSERT_EQUALS(output, expected);
    }
};