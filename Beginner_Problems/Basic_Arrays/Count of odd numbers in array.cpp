class Solution
{
public:
    int countOdd(int arr[], int n)
    {
        int oddCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2)
            {
                oddCount += 1;
            }
        }
        return oddCount;
    }
};
