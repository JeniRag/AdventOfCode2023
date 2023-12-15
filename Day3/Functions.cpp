#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>       //for summing ab vector
#include <bits/stdc++.h> //to find maximum of vector
#include <regex>

/*
This function finds all digits that are adjacent to a symbol and sums them up.
  - file_path: input file path

Returns: The sum of the digits adjacent to a symbol.
*/
int GondolaEnginesSum(std::string file_path) // input a dictionary
{
    std::vector<int> AdjacentDigits;
    std::map<int, std::vector<int>> symbolCoord; // dictionary with line index as key and the column index where the symbol appears as values

    std::fstream inputFile;
    inputFile.open(file_path, std::ios::in);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 1;
    }
    // Check if file is open
    if (inputFile.is_open())
    {
        std::string line;
        int lineIndex = 0;

        while (getline(inputFile, line))
        {
            line = std::regex_replace(line, std::regex("\\r\\n|\\r|\\n"), ""); // remove newline characte
            std::vector<int> symbolCol;                                        // symbol column
            auto symbolPos = line.find_first_not_of("0123456789. ", 0);

            while (symbolPos != std::string::npos)
            {
                std::string symbolString = line.substr(symbolPos, 1);
                // std::cout << "Line " << lineIndex << " : " << symbolString << " at position " << symbolPos << std::endl;
                symbolCol.push_back(symbolPos);
                symbolPos = line.find_first_not_of("0123456789. ", symbolPos + 1);
            }
            symbolCoord[lineIndex] = symbolCol;
            lineIndex += 1;
        }
    }
    inputFile.close();

    inputFile.open(file_path, std::ios::in);

    if (inputFile.is_open())
    { // Reset the file pointer to the beginning of the file or close and reopen it again
        std::string line;

        int lineIndexInt = 0;

        while (getline(inputFile, line))
        {

            // digiits
            auto intPos = line.find_first_of("0123456789", 0);

            while (intPos != std::string::npos)
            {

                // bool adjacent = false; //assume first that each number has no adjacent number
                auto endPos = line.find_first_not_of("0123456789", intPos); // index where there is no more digit

                std::string intString = line.substr(intPos, endPos - intPos);
                int digit = std::stoi(intString); // convert ID string to integer

                std::vector<int>::iterator itLeft;
                std::vector<int>::iterator itRight;

                std::vector<int>::iterator itUp;
                std::vector<int>::iterator itLow;

                std::vector<int> sameRowSymbols;
                std::vector<int> upperRowSymbols;
                std::vector<int> lowerRowSymbols;

                auto leftBound = intPos - 1;
                auto rightBound = endPos;

                if (leftBound == std::string::npos)
                {

                    leftBound = intPos;
                }
                if (rightBound == std::string::npos)
                {
                    rightBound = endPos - 1;
                    rightBound = line.length();
                }

                // check left and right

                if (symbolCoord.find(lineIndexInt) != symbolCoord.end())
                {

                    sameRowSymbols = symbolCoord.find(lineIndexInt)->second;
                    itLeft = std::find(sameRowSymbols.begin(), sameRowSymbols.end(), intPos - 1);
                    itRight = std::find(sameRowSymbols.begin(), sameRowSymbols.end(), endPos);
                }

                // check upper row
                int upperLine = lineIndexInt - 1;
                if (symbolCoord.find(upperLine) != symbolCoord.end()) // check if key exist in dictionary
                {
                    upperRowSymbols = symbolCoord.find(upperLine)->second; // extract the values

                    itUp = std::find_if(upperRowSymbols.begin(), upperRowSymbols.end(), [leftBound, rightBound](const auto &element)
                                        { return leftBound <= element && element <= rightBound; });
                }

                // check lower Row
                int lowerLine = lineIndexInt + 1;
                if (symbolCoord.find(lowerLine) != symbolCoord.end())
                {

                    lowerRowSymbols = symbolCoord.find(lowerLine)->second;

                    itLow = std::find_if(lowerRowSymbols.begin(), lowerRowSymbols.end(), [leftBound, rightBound](const auto &element)
                                         { return leftBound <= element && element <= rightBound; });
                }

                if ((itLeft != sameRowSymbols.end()) || (itRight != sameRowSymbols.end()) || (itUp != upperRowSymbols.end()) || (itLow != lowerRowSymbols.end()))
                {
                    AdjacentDigits.push_back(digit);
                }

                intPos = line.find_first_of("0123456789", endPos);
            }

            lineIndexInt += 1;
        }
    }

    inputFile.close();
    int sum = std::accumulate(AdjacentDigits.begin(), AdjacentDigits.end(), 0);

    return sum;
}

/*
This function compares the adjacent digits to '*' symbols and calculates their product sum.
Parameters:
  - symbolCoord: Map containing symbol coordinates
  - digitCoord: Map containing digit coordinates
Returns: The sum of products of adjacent digits to '*'
*/
int FindProductSum(std::map<int, std::vector<int>> &symbolCoord, std::map<int, std::vector<std::tuple<int, int, int>>> &digitCoord) // take references
{
    /*Take the coordinate information of the symbol * and of all digits in input. Compare which digit are adjacent to a * sign and multiply them and sum the products.*/
    
    std::cout<<"--------"<<std::endl;

    std::vector<int> sums;
    for (auto iter = symbolCoord.begin(); iter != symbolCoord.end(); ++iter)
    {
        int currentRow = iter->first; // The key (integer)
        int upperRow = currentRow - 1;
        int lowerRow = currentRow + 1;

        // Access the associated vector
        std::vector<int> &colVector = iter->second;

        auto intUpperRowIter = digitCoord.find(upperRow); //upper row of current star
        auto intCurrentRowIter = digitCoord.find(currentRow); //current row
        auto intLowerRowIter = digitCoord.find(lowerRow); //lower row of current star

        std::vector<int>::iterator iterSymbolCol = colVector.begin();

        for (iterSymbolCol; iterSymbolCol < colVector.end(); iterSymbolCol++)
        {
           //iterater over all * in a row
         

            std::vector<int> numberList;

            // check if any digit adjacent in the upper row
            if (intUpperRowIter != digitCoord.end())
            {

                auto intUpperRow = intUpperRowIter->second;
                for (auto &tuple : intUpperRow)
                {
                    int startCol = std::get<0>(tuple);
                    int endCol = std::get<1>(tuple);
                    int digit = std::get<2>(tuple);

                    if (*iterSymbolCol >= startCol - 1 && *iterSymbolCol <= endCol)
                    {
                        
                        numberList.push_back(digit);
                    }
                }
            }

            if (intLowerRowIter != digitCoord.end())
            {
                auto  intLowerRow = intLowerRowIter->second;

                for (auto &tuple : intLowerRow)
                {
                    int startCol = std::get<0>(tuple);
                    int endCol = std::get<1>(tuple);
                    int digit = std::get<2>(tuple);

                    if (*iterSymbolCol >= startCol - 1 && *iterSymbolCol <= endCol)
                    {
                        
                        numberList.push_back(digit);
                    }
                }
            }

            if (intCurrentRowIter != digitCoord.end())
            {

                auto intCurrentRow = intCurrentRowIter->second;

                for (auto &tuple : intCurrentRow)
                {
                    int startCol = std::get<0>(tuple);
                    int endCol = std::get<1>(tuple);
                    int digit = std::get<2>(tuple);

                    if (*iterSymbolCol == endCol || *iterSymbolCol == startCol+1) // number left of *
                    {
                        
                        numberList.push_back(digit);
                    }

                    else if (*iterSymbolCol == startCol - 1 )
                    { // number right of *
                        
                        numberList.push_back(digit);
                    }
                }
            }

            if (numberList.size() == 2)
            { // exactly 2 adjacent digits to *
                int prod = numberList[0] * numberList[1];
                sums.push_back(prod);
                //std::cout<<"product: "<<numberList[0]<<" * "<<numberList[1]<<" = " << prod<<std::endl;
            }
        }
    }

    int sum = std::accumulate(sums.begin(), sums.end(), 0);
    return sum;
}

/*
This function finds the coordinates of digits and the integers and finds adjacent digits to '*' symbols and calculates their product sum.
Parameters:
  - file_path: input file path
Returns: The sum of products of adjacent digits to '*'
*/

int SumStarDigits(std::string file_path) // input a dictionary
{
    std::vector<int> AdjacentDigits;
    std::map<int, std::vector<int>> symbolCoord; // dictionary with line index as key and the column index where the symbol appears as values

    std::fstream inputFile;
    inputFile.open(file_path, std::ios::in);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return 1;
    }
    // Check if file is open
    else
    {
        std::string line;
        int lineIndex = 0;

        while (getline(inputFile, line))
        {
            line = std::regex_replace(line, std::regex("\\r\\n|\\r|\\n"), ""); // remove newline characte
            std::vector<int> symbolCol;                                        // symbol column
            auto symbolPos = line.find_first_of("*", 0);                       // Finds position of *

            while (symbolPos != std::string::npos)
            {
                // std::string symbolString = line.substr(symbolPos, 1); //extracts symbol
                //  std::cout << "Line " << lineIndex << " : " << symbolString << " at position " << symbolPos << std::endl;
                symbolCol.push_back(symbolPos);                     // add column where * occurs
                symbolPos = line.find_first_of("*", symbolPos + 1); // search for other * within same row
            }
            symbolCoord[lineIndex] = symbolCol; // save columns where * occurs
            lineIndex += 1;
        }
    }
    inputFile.close();

    std::map<int, std::vector<std::tuple<int, int, int>>> digitCoord; // row, {col, endCol, integer}
    inputFile.open(file_path, std::ios::in);

    if (inputFile.is_open())
    { // Reset the file pointer to the beginning of the file or close and reopen it again
        std::string line;

        int lineIndexInt = 0;

        while (getline(inputFile, line))
        {
            std::vector<std::tuple<int, int, int>> tempCoord; // temporary Coordinates of digits

            // digiits
            auto intPos = line.find_first_of("0123456789", 0);

            while (intPos != std::string::npos)
            {

                auto endPos = line.find_first_not_of("0123456789", intPos); // index where there is no more digit

                std::string intString = line.substr(intPos, endPos - intPos); // exxtract int
                int digit = std::stoi(intString);                             // convert ID string to integer

                // check the next integer in the line
                tempCoord.push_back({intPos, endPos, digit});
                intPos = line.find_first_of("0123456789", endPos);
            }

            digitCoord[lineIndexInt] = tempCoord;

            lineIndexInt += 1;
        }
    }

    inputFile.close();
    int sum = FindProductSum(symbolCoord, digitCoord);


    return sum;
}
