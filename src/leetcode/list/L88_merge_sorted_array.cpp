#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] < nums2[j])
            {
                nums1[k] = nums2[j];
                k--; j--;
            }
            else
            {
                nums1[k] = nums1[i];
                k--; i--;
            }
        }
        while(j >= 0)
        {
            nums1[k] = nums2[j];
            k--; j--; 
        }
    }

    void mergeWithForLoop(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i = m + n - 1; i >= 0; --i )
        {
            if(m == 0)
            {
                nums1[i] = nums2[n-1];
                --n;
            }
            else if(n == 0)
            {
                nums1[i] = nums1[m-1];
                --m;
            }
            
            else if(nums1[m-1] < nums2[n-1])
            {
                nums1[i] = nums2[n-1];
                --n;
            }
            else
            {
                nums1[i] = nums1[m-1];
                --m;
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    Solution s;
    s.merge(nums1, 0, nums2, 1);
    for(int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}