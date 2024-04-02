#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int l = 0;
        bool start_with_space = s[s.length() - 1] == ' ';
        if(!start_with_space) l++;

        for(int i = s.length() - 2; i >= 0; i--)
        {   
            
            if(start_with_space && s[i] == ' ') continue;

            if(s[i] != ' ')
            {
                start_with_space = false;
                l++;
            }
            else
            {
                return l;
            }
        }
        return l;
    }
};

int main()
{
    string s1 = "   fly me   to   the moon  ";
    Solution s;
    int l = s.lengthOfLastWord(s1);
    cout << l << endl;
    return 0;
}