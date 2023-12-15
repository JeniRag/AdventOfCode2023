#include "Functions.hpp"
#include <iostream>
#include <map>

int main(int argc, char* argv[]){
    int output;
    int output2;
    std::string file_path="./data/task1_input.txt";

   
    
    output = GondolaEnginesSum(file_path);
    std::cout <<"The sum of task 1: "<< output <<std::endl;

    // std::vector<std::string> colorList = {"red", "blue", "green"};
    // output2=FewestNumberOfCubes(file_path, colorList);
    output2 = SumStarDigits(file_path);
    std::cout <<"The sum of task 2: "<< output2 <<std::endl;


}