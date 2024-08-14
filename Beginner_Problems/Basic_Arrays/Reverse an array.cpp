class Solution
{
public:
    int *reverse(int arr[], int n)
    {
        int *ans = new int[n];
        int k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[k++] = arr[i];
        }
        return ans;
    }
};
