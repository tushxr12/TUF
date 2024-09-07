class Solution
{
public:
    void solve(int ind, int sum, vector<int> &nums, vector<int> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(sum);
            return;
        }

        // Not Pick
        solve(ind + 1, sum, nums, ans);

        // Pick
        solve(ind + 1, sum + nums[ind], nums, ans);
    }

    vector<int> subsetSums(vector<int> &nums)
    {
        // your code goes here
        vector<int> ans;
        solve(0, 0, nums, ans);
        return ans;
    }
};