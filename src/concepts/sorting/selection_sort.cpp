#include <vector>

using namespace std;


class SelectionSort
{
private:
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void sort(vector<int>& lst)
    {
        for(int i = 0; i < lst.size() - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < lst.size(); j++)
            {
                if (lst[j] < lst[min_idx])
                {
                    min_idx = j;
                }
            }
            swap(lst[i], lst[min_idx]);
        }
    }
};
