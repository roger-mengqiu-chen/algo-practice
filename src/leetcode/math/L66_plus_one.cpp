#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i;
        for(i = digits.size() - 1; i >= 0; i--)
        {
            if(digits[i] == 9) digits[i] = 0;
            else
            {
                digits[i] += 1;
                return digits;
            }
        }

        if(i < 0) digits.insert(digits.begin(), 1);

        return digits;
    }

    void plusOneWithReursion(vector<int>& digits, int l)
    {
        int num = digits[l-1] + 1;
        if(num < 10)
        {
            digits[l-1] = num;
        }
        else
        {
            digits[l-1] = num % 10;

            if(l > 1) plusOneWithReursion(digits, l-1);
            else digits.insert(digits.begin(), 1);
        }
    }
};

int main()
{
    vector<int> v = {9, 9};
    Solution s;
    s.plusOneWithReursion(v, v.size());
    vector<int> expect = {1, 0, 0};
    cout << (v == expect) << endl;
    return 0;
}