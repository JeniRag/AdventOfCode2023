#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>  // std::transform
#include <functional> // std::plus
#include "Race.hpp"

Race::Race(long time, long distance){
    mTime = time;
    mDistance = distance;

    
}

long Race::getTime(){
    return mTime;
}

long Race::getDistance(){
    return mDistance;
}


/**
 * @brief calculates the possible number of wins for the race
 * 
 * @return ** long total number of  possible
 */
long Race::getPossibleNumberOfWins(){

    long waysToWin=0;

    for (long buttonPressed = 0; buttonPressed <= mTime; buttonPressed++){
        long timeLeft = mTime - buttonPressed;
        long velocity = buttonPressed;
        long travelledDist = timeLeft * velocity; //travelled distance

        if (travelledDist > mDistance){ //if travelled distance greated than the given race distance
            waysToWin += 1;
        }


    }
    return waysToWin;
}