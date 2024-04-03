#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int removeElemenet(vector<int>& v, int target)
    {
        int count = 0;
        vector<int> res;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] != target)
            {
                res.push_back(v[i]);
                count ++;
            }
        }

        for (int i = 0; i < count; i++)
        {
            v[i] = res[i];
        }
        return count;
    } 
    
    int removeElementWithoutVector(vector<int>& v, int target)
    {
        int j;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] != target)
            {
                v[j] = v[i];
                j++;
            }
        }
        return j;
    }
};

int main()
{
    vector<int> v = {3,2,2,3};
    Solution s;
    int r = s.removeElemenet(v, 3);
    cout << r << endl;
    for(int n : v)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}