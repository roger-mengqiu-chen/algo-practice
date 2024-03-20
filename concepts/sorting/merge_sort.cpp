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

        l[mid - left + 1] = INT_MAX;  // sentinel
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

    void merge_without_sentinel(int* arr, int left, int mid, int right)
    {
        int* l = new int[mid - left + 1];
        copy(arr + left, arr + mid + 1, l);
        int* r = new int[right - mid];
        copy(arr + mid + 1, arr + right + 1, r);

        int i = 0, j = 0;
        int m = left;
        while(i < mid - left + 1 && j < right - mid)
        {
            if(l[i] < r[j])
            {
                arr[m] = l[i];
                i++;
            }
            else
            {
                arr[m] = r[j];
                j++;
            }
            m++;
        }
        while(i < mid - left + 1)
        {
            arr[m] = l[i];
            i++;
            m++;
        }
        while(j < right - mid)
        {
            arr[m] = r[j];
            j++;
            m++;
        }

        delete[] l;
        delete[] r;
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

    void sort_without_sentinel(int* arr, int left, int right)
    {
        if(left < right)
        {
            int mid = (right - left) / 2 + left;
            sort(arr, left, mid);
            sort(arr, mid+1, right);
            merge_without_sentinel(arr, left, mid, right);
        }
    }
};
