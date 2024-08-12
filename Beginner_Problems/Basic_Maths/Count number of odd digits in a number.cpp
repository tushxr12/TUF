class Solution
{
public:
    int countOddDigit(int n)
    {
        int ans = 0;
        string nToString = to_string(n);
        for (auto i : nToString)
        {
            if ((i - '0') % 2)
                ans++;
        }
        return ans;
    }
};