#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        vector<int> res;
        int count = 1;
        int num = nums.size();
        res.push_back(nums[0]);
        for (int i = 1; i < num; i++)
        {
            if(res.back() != nums[i])
            {
                res.push_back(nums[i]);
                count ++;
            }
        }
        
        for(int i = 0; i < count; i++)
        {
            nums[i] = res[i];
        }
        return count; 
    }
};
