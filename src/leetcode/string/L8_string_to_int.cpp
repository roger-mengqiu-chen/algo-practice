#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int i = 0;
        int sign = 1;
        while(i < s.length() && s[i] == ' ')
            i++;

        if(s[i] == '-') {
            sign = -1;
            i++;
        }

        else if(s[i] == '+'){
            i++;
        }



        for(; i < s.length(); i++) {
            char c = s[i];
            if(c >= '0' && c <= '9'){
                res = res * 10 + c - '0';

                if(res > INT_MAX && sign == -1) {
                    return INT_MIN;
                }
                else if(res > INT_MAX && sign == 1) {
                    return INT_MAX;
                }
            }
            else {
                break;
            }
        }

         res = sign * res;
        
        return res;
    }
};

int main() {
    string s1 = "+-123";
    Solution s;
    int r = s.myAtoi(s1);
    cout << r << endl;
    cout << endl;
    return 0;
}