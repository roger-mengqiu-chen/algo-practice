#include <vector>
#include <unordered_map>
#include <algorithm>


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


class CountTwoSumEqualsZero{
public:
    int count(vector<int> arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i-1]) continue;

            auto it = std::lower_bound(arr.begin() + i + 1, arr.end(), -arr[i]);

            if(it != arr.end() && *it == -arr[i]) c++;
        }
        return c;
    }
};
