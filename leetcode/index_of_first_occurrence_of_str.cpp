#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        if(haystack_size == needle_size) return 0;
        for(int i = 0; i <= haystack_size; i++ )
        {
            if(haystack.substr(i, needle_size) == needle) return i;
        }
        return -1;
    }

    int strStrWithFind(string haystack, string needle)
    {
        size_t it = haystack.find(needle);
        return it;
    }

    int strStrWithRabinKarp(string haystack, string needle)
    {
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        if(needle_size > haystack_size) return -1;

        long long mod = 1e9+7, req_hash = 0;
        
        // hashing needle
        for(int i = 0; i < needle_size; i++)
        {
            // why 27? Because there are 26 lower case English letters and 27 is the smallest number bigger than 26.
            req_hash = req_hash * 27 + (needle[i] - 'a' + 1);
            req_hash %= mod;
        }

        long long roll_hash =0, mul = 1;
        for(int i = 0; i < haystack_size; i++)
        {
            // get hash value for substring from 0 to index i
            roll_hash = roll_hash * 27 + (haystack[i] - 'a' + 1);
            roll_hash %= mod;

            if (i < needle_size - 1)
            {
                mul *= 27;
                mul %= mod;
            }
            else
            {
                if(roll_hash == req_hash) 
                    return i - needle_size + 1;  // get the starting index of current window

                roll_hash = (roll_hash
                            - (mul * (haystack[i - needle_size + 1] - 'a' + 1)) % mod 
                            + mod)  // subtract the hash value of the removed character from current roll hash
                            % mod;
            }
        }
        return -1;
    }
};
