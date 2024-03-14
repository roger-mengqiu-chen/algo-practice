#include <vector>
#include <unordered_map>

using namespace std;

/*
Assume that there is only one combination in the nums
*/
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i ){
            if (map.find(target - nums[i]) != map.end()) {
                return { map[target - nums[i]], i };
            }
            // Store number and its index
            map[nums[i]] = i;
        }
        return {};
    }
};
