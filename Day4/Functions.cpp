#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>       //for summing ab vector
#include <bits/stdc++.h> //to find maximum of vector
#include <regex>

/*
Calculates the points of the scratchcard.
  - file_path: input file path

Returns: The points.
*/
int GetPointsOfSratchcard(std::string file_path) // input a dictionary
{
    int sum = 0;

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

        while (getline(inputFile, line))
        {

            std::vector<int> winningNumbers;
            std::vector<int> yourNumbers;

            auto seperatorPosition = line.find_first_of("|"); // Find the seperator location
            auto columnPosition = line.find_first_of(":");

            auto intPos = line.find_first_of("0123456789", columnPosition);

            while (intPos != std::string::npos && intPos < seperatorPosition)
            {

                auto endPos = line.find_first_not_of("0123456789", intPos);   // index where there is no more digit
                std::string intString = line.substr(intPos, endPos - intPos); // exxtract int

                int digit = std::stoi(intString);
                winningNumbers.push_back(digit);

                intPos = line.find_first_of("0123456789", endPos);
            }

            intPos = line.find_first_of("0123456789", seperatorPosition);

            while (intPos != std::string::npos)
            {

                auto endPos = line.find_first_not_of("0123456789", intPos);   // index where there is no more digit
                std::string intString = line.substr(intPos, endPos - intPos); // exxtract int

                int digit = std::stoi(intString);
                yourNumbers.push_back(digit);

                intPos = line.find_first_of("0123456789", endPos);
            }

            // sort both vectors
            sort(winningNumbers.begin(), winningNumbers.end());
            sort(yourNumbers.begin(), yourNumbers.end());

            // for (const auto &number : winningNumbers)
            // {
            //     std::cout << number << " ";
            // }
            // std::cout << " | ";
            // for (const auto &number : yourNumbers)
            // {
            //     std::cout << number << " ";
            // }
            // std::cout << std::endl;

            std::vector<int> intersection(winningNumbers.size() + yourNumbers.size());
            std::vector<int>::iterator it;
            it = std::set_intersection(winningNumbers.begin(), winningNumbers.end(), yourNumbers.begin(), yourNumbers.end(), intersection.begin());

            intersection.resize(it - intersection.begin()); // it has the position one past the last element. The difference gives the size of the intersection

            // std::cout << "intersections: ";
            // for (const auto &number : intersection)
            // {
            //     std::cout << number << " ";
            // }

            if (intersection.size() > 0)
            {
                int point = pow(2, intersection.size() - 1);

                sum += point;
            }
        }
    }
    inputFile.close();

    return sum;
}

/*
Recursive function to determine copies.
  - CardIndexes: Vector containing the card indices
  - CardMatches: Mapt to look up the number of matching digits for each card
  - sum: to sum up the number of copies

Returns: The points.
*/
void CountCopies(std::vector<int> &CardIndexes, std::map<int, int> const &CardMatches, int &sum)
{


    if (CardIndexes.empty())
    {
        return;
    }

    std::vector<int> Copies;
    for (auto const &cards : CardIndexes)
    {
        auto matchIter = CardMatches.find(cards);
        if (matchIter != CardMatches.end() && matchIter->second > 0) // number of matches > 0
        {
            int match = matchIter->second;

            int start = cards + 1;
            int end = cards + match + 1;

            if (end > CardMatches.size())
            {
                end = CardMatches.size()+1;
            }

            for (int i = start; i < end; i++)
            {

                Copies.push_back(i);
            }
        }
    }
    sum += Copies.size();
    CountCopies(Copies, CardMatches, sum);
}
/*
Calculates the points of the scratchcard.
  - file_path: input file path

Returns: The points.
*/

int GetNumberOfCopies(std::string file_path) // input a dictionary
{
    std::map<int, int> CardMatches; // Cardindex, Number of Matches

    std::map<int, std::vector<int>, std::vector<int>> ScratchCard; // Scratchcard index, winning Numbers, your Numbers

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
        int CardIndex = 1;

        while (getline(inputFile, line))
        {

            std::vector<int> winningNumbers;
            std::vector<int> yourNumbers;

            auto seperatorPosition = line.find_first_of("|"); // Find the seperator location
            auto columnPosition = line.find_first_of(":");

            auto intPos = line.find_first_of("0123456789", columnPosition);

            while (intPos != std::string::npos && intPos < seperatorPosition)
            {

                auto endPos = line.find_first_not_of("0123456789", intPos);   // index where there is no more digit
                std::string intString = line.substr(intPos, endPos - intPos); // exxtract int

                int digit = std::stoi(intString);
                winningNumbers.push_back(digit);

                intPos = line.find_first_of("0123456789", endPos);
            }

            intPos = line.find_first_of("0123456789", seperatorPosition);

            while (intPos != std::string::npos)
            {

                auto endPos = line.find_first_not_of("0123456789", intPos);   // index where there is no more digit
                std::string intString = line.substr(intPos, endPos - intPos); // exxtract int

                int digit = std::stoi(intString);
                yourNumbers.push_back(digit);

                intPos = line.find_first_of("0123456789", endPos);
            }

            // ScratchCard.insert({CardIndex, winningNumbers, yourNumbers});

            // sort both vectors
            sort(winningNumbers.begin(), winningNumbers.end());
            sort(yourNumbers.begin(), yourNumbers.end());

            std::vector<int> intersection(winningNumbers.size() + yourNumbers.size());
            std::vector<int>::iterator it;
            it = std::set_intersection(winningNumbers.begin(), winningNumbers.end(), yourNumbers.begin(), yourNumbers.end(), intersection.begin());

            intersection.resize(it - intersection.begin()); // it has the position one past the last element. The difference gives the size of the intersection

            CardMatches.insert({CardIndex, intersection.size()});
            CardIndex += 1;
        }
    }
    inputFile.close();
    std::vector<int> CardIndexes;
    for (auto const &cards : CardMatches)
    {
        CardIndexes.push_back(cards.first);
    }

    int sum = CardIndexes.size();

    CountCopies(CardIndexes, CardMatches, sum);
    return sum;
}
