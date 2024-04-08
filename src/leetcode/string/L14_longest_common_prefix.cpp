#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res;
        sort(strs.begin(), strs.end());

        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];

        for(int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if(s1[i] != s2[i]) return res;
            res += strs[i];
        }
        return res;
    }
};
