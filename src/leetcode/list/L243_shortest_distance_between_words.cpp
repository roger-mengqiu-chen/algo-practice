#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int idx1 = -1, idx2 = -1, ans = 3e4;

        for(int i = 0; i < wordsDict.size(); i++)
        {
            
            if(wordsDict[i] == word1) idx1 = i;
            else if(wordsDict[i] == word2) idx2 = i;

            if(idx1 >= 0 && idx2 >=0)
                ans = min(ans, abs(idx1 - idx2));

        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ss = {"practice", "makes", "perfect", "coding", "makes"};
    int res = s.shortestDistance(ss, "coding", "practice");
    cout << res << endl;
    return 0;
}