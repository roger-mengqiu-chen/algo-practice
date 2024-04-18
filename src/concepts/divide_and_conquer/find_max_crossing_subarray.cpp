#include <vector>
#include <iostream>

/* Buy first and then sell it. Find out the max revenue from the list. If the best < 0, return 0 */

using namespace std;

class Solution {
public:
    /* O(n^2) */
    int maxRenvenueWithBruteForce(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                int t = prices[j] - prices[i];
                res = t > res ? t : res;
            }
        }
        return res;
    }

    int maxRenvenue(vector<int>& prices) {
        vector<int>changes;
        for(int i = 1; i < prices.size(); i++) {
            changes.push_back(prices[i] - prices[i-1]);
        }

        int maxSub = changes[0];
        int cur = 0;

        for(int n : changes) {
            if(cur < 0) {
                cur = 0;
            }
            cur += n;
            maxSub = max(maxSub, cur);
        }
        return maxSub;
    }
};

int main() {
    vector<int> prices = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    Solution s;
    int res = s.maxRenvenueWithBruteForce(prices);
    
    cout << res << endl;
    cout << endl;
    return 0;
}