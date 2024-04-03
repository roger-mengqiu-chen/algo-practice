#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x == 0 || x == 1) return x;

        int left = 0, right = x;
        int mid;

        while(right - left > 1)
        {
            mid = (right - left) / 2 + left;
            int m = x / mid;
            if(m > mid) left = mid;
            else if (m < mid) right = mid;
            else return mid;
        }
        return left;
    }
};

int main()
{
    Solution s;
    int res = s.mySqrt(8);
    cout << res << endl;
    return 0;
}
