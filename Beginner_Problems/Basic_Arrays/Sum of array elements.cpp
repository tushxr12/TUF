class Solution
{
public:
    int sum(int arr[], int n)
    {
        int summ = 0;
        for (int i = 0; i < n; i++)
        {
            summ += arr[i];
        }
        return summ;
    }
};