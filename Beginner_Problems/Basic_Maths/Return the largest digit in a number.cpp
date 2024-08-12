class Solution
{
public:
    int largestDigit(int n)
    {
        int ans = -1;
        string nToString = to_string(n);
        for (auto i : nToString)
        {
            if (i - '0' > ans)
            {
                ans = max(ans, i - '0');
            }
        }
        return ans;
    }
};