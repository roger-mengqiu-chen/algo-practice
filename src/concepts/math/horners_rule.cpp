class HornersRule
{
public:
    int calculate(int* poly, int size, int x)
    {
        int result = poly[0];
        for(int i = 1; i < size; i++)
        {
            result = result * x + poly[i];
        }
    }
};