#include <vector>
#include <iostream>
#include <algorithm>
#include <random>


class QuickSort {
private:

    void randomize(std::vector<int> arr) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(arr.begin(), arr.end(), g);
    }

    void swap(std::vector<int>& arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    int partition(std::vector<int>& arr, int first, int last) {
        int pivot_value = arr[first];
        int left = first + 1;
        int right = last;

        while (1) {
            while (left <= right && arr[left] <= pivot_value) {
                left ++;
            }
            while (arr[right] >= pivot_value && right >= left) {
                right --;
            }

            if (right < left) break;

            else swap(arr, left, right);
        }

        swap(arr, first, right);
        return right;
    }

    void quickSortHelper(std::vector<int>& arr, int first, int last) {
        if (first < last) {
            int pivot = partition(arr, first, last);

            quickSortHelper(arr, first, pivot - 1);
            quickSortHelper(arr, pivot + 1, last);
        }
    }

public:
    void sort(std::vector<int>& arr) {
        randomize(arr);
        quickSortHelper(arr, 0, arr.size() - 1);
    }
};


int main() {
    QuickSort s;
    std::vector<int> arr = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    s.sort(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}