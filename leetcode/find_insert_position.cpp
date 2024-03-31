#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findInsertionPosition(vector<int>& nums, int target)
    {
        
        int left = 0, right = nums.size();
    
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            int mid_val = nums[mid];

            if (mid_val >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;    
            }
        }
        return left;
    }
};

int main()
{
    vector<int> v = {1, 3, 5, 6};
    Solution s;
    int res = s.findInsertionPosition(v, 7);
    cout << res << endl;
    return 0;
}