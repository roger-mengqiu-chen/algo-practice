#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result = {};
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++)
        {
            m[list1[i]] = i;
        }
        int sum = 2000;
        for(int i = 0; i < list2.size(); i++)
        {
            string word = list2[i];
            if(m.count(list2[i]))
            {
                int s = i + m[word];
                if(sum == s) result.push_back(word);
                else if (s < sum ) 
                {
                    result.clear();
                    result.push_back(word);
                    sum = s;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KFC","Shogun","Burger King"};
    Solution s;
    vector<string> res = s.findRestaurant(list1, list2);
    for (string ss : res)
    {
        cout << ss << " ";
    }
    cout << endl;
    return 0;
}