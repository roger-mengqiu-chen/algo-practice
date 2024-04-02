#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        char f = '0';
        while(i >= 0 || j >= 0)
        {
            char ac = '0', bc = '0';
            if(i >= 0) 
            {
                ac = a[i];
                i--;
            }
            if(j >= 0) 
            {
                bc = b[j];
                j--;
            }

            int x = ac + bc + f;
            switch(x)
            {
                case 144: res.insert(0, "0"); f = '0'; break;
                case 145: res.insert(0, "1"); f = '0'; break;
                case 146: res.insert(0, "0"); f = '1'; break;
                case 147: res.insert(0, "1"); f = '1'; break;
            }
        }
        if(f > '0') res.insert(0, "1");
        return res;
    }
};

int main()
{
    string a = "11";
    string b = "1";
    Solution s;
    string res = s.addBinary(a, b);
    string expect = "10101";
    
    cout << res << endl;
    return 0;
}