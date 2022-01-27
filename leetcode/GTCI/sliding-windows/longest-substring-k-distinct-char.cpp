#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


// place each char in a map, incrementing by one
// size of map = number of distinct chars
// if size of map is greater than k = more than k distinct characters, 
    // the window size needs to be decreased from beginning until window has <= k distinct char
    // move start up, decrementing the char in map
    // and erasing it if value <= 0. repeat this in while loop
    // when loop breaks, window contains no more than k distinct chars
// else, get new max length


int longest_substring_k_distinct_chars(std::string str, int k)
{
    std::map<char, int> hash_map;
    int start = 0, length = -1;

    for (int end = 0; str[end] != '\0'; end++)
    {
        hash_map[str[end]]++;

        while(hash_map.size() > k)
        {
            hash_map[str[start]]--;

            if(hash_map[str[start]] <= 0)
                hash_map.erase(str[start]);

            start++;
        }
        
        length = std::max(length, end - start + 1);
    }

    return length;
};

int main()
{
    std::cout << longest_substring_k_distinct_chars("araaci", 2)  << std::endl; // 4
    std::cout << longest_substring_k_distinct_chars("araaci", 1)  << std::endl; // 2
    std::cout << longest_substring_k_distinct_chars("cbbebi", 3)  << std::endl; // 5
}