#include <vector>
#include <iostream> 

using namespace std;

class InsertionSort 
{
public:
    void sort(vector<int>& arr) 
    {   
        for (int i = 1; i < arr.size(); ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void recursive_sort(vector<int>& arr, int n)
    {
        if(n <= 1) return;

        recursive_sort(arr, n - 1);

        int last = arr[n-1];
        int j = n - 2;

        while(j >= 0 && arr[j] > last)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }
};


class ShellSort {

public:
    void sort(vector<int>& arr , int gap) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /=0) {
            for (int i = gap; i < n; i++) {
                int key = arr[i];
                int j = i - gap;
                while (j >= 0 && arr[i] > key) {
                    arr[j + gap] = arr[i];
                    j -= gap;
                }
                arr[j + gap] = key;
            }
        }
    }
};


int main() {
    std::vector<int> v = {5,4,3,2,1};
    ShellSort s;
    s.sort(v, 3);
    for (int i : v) {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
    return 0;
}
