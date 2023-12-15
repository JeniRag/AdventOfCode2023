#include "Functions.hpp"
#include <iostream>
#include <map>

int main(int argc, char* argv[]){
    int output;
    int output2;
    std::string file_path="./data/task1_input.txt";

   
    
    output = GetPointsOfSratchcard(file_path);
    std::cout <<"The sum of task 1: "<< output <<std::endl;

    output2 = GetNumberOfCopies(file_path);
    std::cout <<"The sum of task 2: "<< output2 <<std::endl;


}