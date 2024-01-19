#ifndef RACELISTHEADERDEF
#define RACELISTHEADERDEF
#include <iostream>
#include <vector>
#include <map>


class Race
{

private:
    long mTime;
    long mDistance;

public:
    friend class MyTestSuite;
    Race(long time, long distance); // constructor

    
    // Getters
    long getTime();
    long getDistance();

    //Methods
    long getPossibleNumberOfWins(); // number of possibilities to win
    

    

};

#endif