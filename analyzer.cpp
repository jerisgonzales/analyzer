#include <iostream>
#include <cmath>
#include "StringData.h"
using namespace std;
int linear_search(std::vector<std::string> container, std::string element){
    for(int x=0; x < sizeof(container); x++){
        if(container[x]==element){
            return x;
        }
    }
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element){
    int minIndex = 0;
    int maxIndex = sizeof(container);
    int midIndex;

    while(minIndex<=maxIndex){
        midIndex = minIndex + floor((maxIndex - minIndex) / 2);
        if (container[midIndex] == element){
            return midIndex;
        }
        else if (container[midIndex] > element) {
            maxIndex = midIndex - 1;
        }
        else if (container[midIndex] < element){
            minIndex = midIndex + 1;
        }

    }
    return -1;
}

int main() {
    std::vector<std::string> data = getStringData();

    cout << "Linear Search for 'not_here': \n";
    long initialTime = systemTimeNanoseconds()/1000000000;
    cout << "The index of the linear search is:";
    int LinearSearch1 = linear_search(data, "not_here");
    cout <<LinearSearch1;
    long finalTime = systemTimeNanoseconds()/1000000000;
    long timeElapsed = initialTime-finalTime;
    cout << "\nTime elapsed:";
    cout << timeElapsed;
    cout << "\nBinary Search for 'not_here':";
    initialTime = systemTimeNanoseconds()/1000000000;
    cout << "\nThe index of the binary search is:";
    int BinarySearch1 = binary_search(data, "not_here");
    cout <<BinarySearch1;
    finalTime = systemTimeNanoseconds()/1000000000;
    timeElapsed = initialTime-finalTime;
    cout << "\nTime elapsed:";
    cout << timeElapsed;

    cout << "\n\nLinear Search for 'mzzzz': \n";
    initialTime = systemTimeNanoseconds()/1000000000;
    cout << "The index of the linear search is:";
    int LinearSearch2 = linear_search(data, "zzzzz");
    cout <<LinearSearch2;
    finalTime = systemTimeNanoseconds()/1000000000;
    timeElapsed = initialTime-finalTime;
    cout << "\nTime elapsed:";
    cout << timeElapsed;
    cout << "\nBinary Search for 'zzzzz':";
    initialTime = systemTimeNanoseconds()/1000000000;
    cout << "\nThe index of the binary search is:";
    int BinarySearch2 = binary_search(data, "zzzzz");
    cout <<BinarySearch2;
    finalTime = systemTimeNanoseconds()/1000000000;
    timeElapsed = initialTime-finalTime;
    cout << "\nTime elapsed:";
    cout << timeElapsed;

    cout << "\n\nLinear Search for 'aaaaa': \n";
    initialTime = systemTimeNanoseconds()/1000000000;
    cout << "The index of the linear search is:";
    LinearSearch1 = linear_search(data, "aaaaa");
    cout <<LinearSearch1;
    finalTime = systemTimeNanoseconds()/1000000000;
    timeElapsed = initialTime-finalTime;
    cout << "\nTime elapsed:";
    cout << timeElapsed;
    cout << "\nBinary Search for 'not_here':";
    initialTime = systemTimeNanoseconds()/1000000000;
    cout << "\nThe index of the binary search is:";
    BinarySearch1 = binary_search(data, "aaaaa");
    cout <<BinarySearch1;
    finalTime = systemTimeNanoseconds()/1000000000;
    timeElapsed = initialTime-finalTime;
    cout << "\nTime elapsed:";
    cout << timeElapsed;




    return 0;
}

