// Brute
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), mp = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int pr = 1;
            for (int j = i; j < n; j++)
            {
                pr *= nums[j];
                mp = max(mp, pr);
            }
        }
        return mp;
    }
};

// Optimal (Observational)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pr = 1, su = 1;
        int mp = INT_MIN, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (pr == 0)
                pr = 1;
            if (su == 0)
                su = 1;
            pr *= nums[i];
            su *= nums[n - i - 1];
            mp = max(mp, max(su, pr));
        }
        return mp;
    }
};