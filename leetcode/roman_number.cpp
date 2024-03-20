#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int romanNumber(string s)
    {
        int result = 0;
        int pre = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int num;
            switch(s[i])
            {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }

            if (num <= pre)
            {
                result += num;
            }
            else
            {
                result = result - pre * 2 + num;
            }
            pre = num;
        }

        return result;
    }
};
