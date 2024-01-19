#include "Functions.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    int output;
    int output2;
    std::string file_path="./data/task1_input.txt";
    
    // output = FindLowestLocation(file_path);
    // std::cout <<"The lowest location of task 1: "<< output <<std::endl;

    output2 = FindLowestLocationFromRanges(file_path);
    std::cout<< "The lowest location of task 2: "<< output2<<std::endl;


   


}