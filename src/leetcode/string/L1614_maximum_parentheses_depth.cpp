#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int d = 0, n = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                n ++;
            }
            else if(s[i] == ')')
            {
                n --;
            }

            if(n > d) d = n;
        }
        return d;
    }
};

int main()
{
    Solution s;
    int res = s.maxDepth("(1+(2*3)+((8)/4))+1");
    cout << res << endl;
    return 0;
}