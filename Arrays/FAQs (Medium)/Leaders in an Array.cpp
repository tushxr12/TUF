// Brute
class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            bool isGreatest = true;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    isGreatest = false;
                    break;
                }
            }
            if (isGreatest)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

// Optimal
class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > maxi)
            {
                ans.push_back(nums[i]);
                maxi = max(maxi, nums[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};