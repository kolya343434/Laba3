/*
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// #include "HashTable.hpp"
#include "IDictionary.hpp"
#include "sequence.hpp"
#include <cstdlib>
#include <ctime>

void wer()
{
    std::vector<int> numbers(10);
    int max_value = -1;
    int min_value = 1000;
    std::cout << "Enter 10 numbers" << '\n';
    for (int i = 0; i < 10; ++i)
    {
        std::cin >> numbers[i];
    }
    for (int i = 0; i < 10; ++i)
    {
        max_value = std::max(max_value, numbers[i]);
        min_value = std::min(min_value, numbers[i]);
    }

    int index = 0;
    for (int i = min_value; i < max_value; i += max_value / 10 + 1)
    { // max_value; i > 0; i-=max_value/10) {
        std::cout.width(2);
        std::cout << i << " - " << i + max_value / 10 << " | ";

        // Marking the values
        int count = 0;
        for (int j = 0; j < 10; ++j)
        {
            if (numbers[j] >= i && numbers[j] <= i + max_value / 10)
            {
                std::cout << "x ";
            }
            else
            {
                std::cout << "";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------"
        << std::endl;
    std::cout << "    ";
}
*/