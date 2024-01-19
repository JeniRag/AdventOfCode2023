#include "Functions.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    int output;
    int output2;
    std::string file_path="./data/task1_input.txt";
    
    output = calculateProduct(file_path);
    std::cout <<"The product of task 1: "<< output <<std::endl;

    output2 = combineInputAndGetProduct(file_path);
    std::cout<< "The result of task 2: "<< output2<<std::endl;
}