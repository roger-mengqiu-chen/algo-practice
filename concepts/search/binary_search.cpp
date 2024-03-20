class BinarySearch
{
public:
    /* arr is sorted */
    int search(int* arr, int target, int size)
    {
        int mid = size / 2;
        int left = 0;
        int right = size;
        while (mid >= left && mid <= right)
        {
            if (arr[mid] > target)
            {
                mid = (mid - left) / 2 + left;
                right = mid - 1;
            }
            else if (arr[mid] < target)
            {
                mid = (right - mid) / 2 + mid;
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    int recursive_search(int* arr, int target, int left, int right)
    {
        int mid = (right - left) / 2 + left;
            if (arr[mid] == target) return mid;

            else if (arr[mid] != target && (mid == 0 || mid == right)) return -1;

            else if (arr[mid] < target)
            {
                left = mid + 1;
                return recursive_search(arr, target, left, right);
            }
            else
            {
                right = mid - 1;
                return recursive_search(arr, target, left, right);
            }
        }
};
