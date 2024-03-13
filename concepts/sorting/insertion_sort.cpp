#include <vector>
#include <iostream>

using namespace std;

class InsertionSort 
{
public:
    vector<int> solution(vector<int>& arr) 
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
        return arr;
    }
};

void print_vector(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() 
{
    std::vector<int> l = { 3, 4, 2, 1}; 
    InsertionSort is = InsertionSort();
    is.solution(l);
    print_vector(l);
    return 0;
}