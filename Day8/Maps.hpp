#ifndef MAPSHEADERDEF
#define MAPSHEADERDEF

#include <iostream>
#include <vector>
#include <map>

class Maps
{

private:
    std::string mDirections;
    std::map<std::string, std::vector<std::string>> mDictionary;

public:
    friend class MyTestSuite;
    Maps(std::string directions, std::map< std::string, std::vector<std::string> >dictionary); // constructor
    //Methods
    int followMap(std::string start, std::string destination);
};

#endif