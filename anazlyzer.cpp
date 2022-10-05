#include <iostream>
#include <string>
#include <vector>
#include "StringData.h"

int binarySearch(std::vector <std::string> searchList, std::string target);
int linearSearch(std::vector <std::string> searchList, std::string target);

int main()
{
    std::vector<std::string> searchList = getStringData();
    std::string phrase = "aaaaa";
    float start = systemTimeNanoseconds() / 1000000000.0f;
    int indexFound = binarySearch(searchList, phrase);
    float end = systemTimeNanoseconds() / (float)1000000000;
    float time = end - start;
    std::cout << "binary search data: phrase = " << phrase << ", index of phrase = " << indexFound << ", time = " << time << "\n";

    phrase = "mzzzz";
    start = systemTimeNanoseconds() / 1000000000.0f;
    indexFound = binarySearch(searchList, phrase);
    end = systemTimeNanoseconds() / (float)1000000000;
    time = end - start;
    std::cout << "binary search data: phrase = " << phrase << ", index of phrase = " << indexFound << ", time = " << time << "\n";

    phrase = "not_here";
    start = systemTimeNanoseconds() / 1000000000.0f;
    indexFound = binarySearch(searchList, phrase);
    end = systemTimeNanoseconds() / (float)1000000000;
    time = end - start;
    std::cout << "binary search data: phrase = " << phrase << ", index of phrase = " << indexFound << ", time = " << time << "\n\n";

    phrase = "aaaaa";
    start = systemTimeNanoseconds() / 1000000000.0f;
    indexFound = binarySearch(searchList, phrase);
    end = systemTimeNanoseconds() / (float)1000000000;
    time = end - start;
    std::cout << "linear search data: phrase = " << phrase << ", index of phrase = " << indexFound << ", time = " << time << "\n";

    phrase = "mzzzz";
    start = systemTimeNanoseconds() / 1000000000.0f;
    indexFound = binarySearch(searchList, phrase);
    end = systemTimeNanoseconds() / (float)1000000000;
    time = end - start;
    std::cout << "linear search data: phrase = " << phrase << ", index of phrase = " << indexFound << ", time = " << time << "\n";

    phrase = "not_here";
    start = systemTimeNanoseconds() / 1000000000.0f;
    indexFound = binarySearch(searchList, phrase);
    end = systemTimeNanoseconds() / (float)1000000000;
    time = end - start;
    std::cout << "linear search data: phrase = " << phrase << ", index of phrase = " << indexFound << ", time = " << time << "\n";
    return 0;
}

int binarySearch(std::vector <std::string> searchList, std::string target)
{
    int low_index = 0;
    int high_index = searchList.size() - 1;
    /* Loops until the value is found */
    while (low_index <= high_index)
    {
        int mid_index = low_index + (high_index - low_index) / 2;
        if (searchList[mid_index] == target)
        {
            return mid_index;
        }
        else if (target > searchList[mid_index])
        {
            low_index = mid_index+1;
        }
        else
        {
            high_index = mid_index - 1;
        }
    }
    return -1;  /* If the value is not found the function returns -1 */
}

int linearSearch(std::vector <std::string> searchList, std::string target)
{
    /* Takes the tuple and target value as input */
    /*  Searches linearly through the tuple */
    for (int index = 0; index < searchList.size(); ++index)
    {
        /*  Compares the tuple value to the target value */
        if (searchList[index] == target)
        {
            return index;
        }
    }
    return -1;
}

