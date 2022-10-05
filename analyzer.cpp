
#include "StringData.h"

inline float nano_sec_to_sec(long long nano_sec)
{
    float conversion = 1.0f/(1000000000);
    return nano_sec*conversion;
}

int linear_search(std::vector<std::string> raw_data, std::string desired_data)
{
    for(int idx = 0;
        idx < raw_data.size();
        idx++)
    {
        if(raw_data[idx] == desired_data)
            return idx;
    }
    
    return -1;
}

int binary_search(std::vector<std::string> raw_data,
                  std::string desired_data)
{
    int mid = 0;
    int start = 0;
    int end = raw_data.size()-1;
    
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(raw_data[mid] == desired_data)
            return mid;
        else if(raw_data[mid] > desired_data)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    
    return -1;
}

void profile_binary_search(std::vector<std::string> raw_data,
                           std::string desired_data)
{
    long long start = systemTimeNanoseconds();
    int idx = binary_search(raw_data, desired_data);
    long long end = systemTimeNanoseconds();
    
    float time = nano_sec_to_sec(end-start);
    
    std::cout << "binary_search: Took " << time << " seconds to find \"" << desired_data << "\" at index " << idx << "\n";
}

void profile_linear_search(std::vector<std::string> raw_data,
                           std::string desired_data)
{
    long long start = systemTimeNanoseconds();
    int idx = linear_search(raw_data, desired_data);
    long long end = systemTimeNanoseconds();
    
    float time = nano_sec_to_sec(end-start);
    
    std::cout << "linear_search: Took " << time << " seconds to find \"" << desired_data << "\" at index " << idx << "\n";
}

int main() 
{
    std::vector<std::string> string_data = getStringData();
    
    profile_binary_search(string_data, "not_here");
    profile_linear_search(string_data, "not_here");
    
    profile_binary_search(string_data, "mzzzz");
    profile_linear_search(string_data, "mzzzz");
    
    profile_binary_search(string_data, "aaaaa");
    profile_linear_search(string_data, "aaaaa");
    
    return 0;
}