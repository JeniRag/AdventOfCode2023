#include "Functions.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    int output;
    int output2;

    std::string file_path="./data/task1_input.txt";
    
    output = getNumberOfSteps(file_path, "AAA", "ZZZ");
    std::cout <<"The number of steps are: "<< output <<std::endl;

    // output2 = combineInputAndGetProduct(file_path);
    // std::cout<< "The result of task 2: "<< output2<<std::endl;
}