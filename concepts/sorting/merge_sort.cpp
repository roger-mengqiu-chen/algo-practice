#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

class MergeSort
{
private:
    void merge(int* arr, int left, int mid, int right)
    {
        int l[mid - left + 2];
        copy(arr + left, arr + mid + 1, l);
        int r[right - mid + 1];
        copy(arr + mid + 1, arr + right + 1, r);

        l[mid - left + 1] = INT_MAX;
        r[right - mid] = INT_MAX;

        int i = 0;
        int j = 0;
        for (int k = left; k < right + 1; k++)
        {
            if (l[i] < r[j])
            {
                arr[k] = l[i];
                i++;
            }
            else
            {
                arr[k] = r[j];
                j++;
            }
        }
    }
public:
    void sort(int* arr, int left, int right)
    {
        if (left < right)
        {
            int mid = (right - left) / 2 + left;
            sort(arr, left, mid);
            sort(arr, mid+1, right);
            merge(arr, left, mid, right);
        }
    }
};


int main()
{
    MergeSort m;
    int arr[5] = {3, 2, 1, 5, 4};
    m.sort(arr, 0, 4);
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}