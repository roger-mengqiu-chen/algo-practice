class BubbleSort
{
private:
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void sort(int* arr, int size)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = size - 1; j > 0; j--)
            {
                if(arr[j] < arr[j-1])
                {
                    swap(arr[j], arr[j-1]);
                }
            }
        }
    }
};
