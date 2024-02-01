#include "Functions.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    int output;
    long output2;

    std::string file_path="./data/task1_input.txt";
    

    output = getSum(file_path, extrapolateNextValue);
    std::cout <<"The sum of task 1: "<< output <<std::endl;

    output2 = getSum(file_path, extrapolateBack);
    std::cout<< "The sum of task 2: "<< output2<<std::endl;
}