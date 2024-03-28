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
};
