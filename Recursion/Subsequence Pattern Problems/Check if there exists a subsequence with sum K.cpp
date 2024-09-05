class Solution
{
public:
    bool solve(int ind, int target, vector<int> &nums)
    {
        if (target == 0)
            return true;

        if (target < 0 || ind == nums.size())
            return false;

        // Not Pick
        bool notPick = solve(ind + 1, target, nums);

        // Pick
        bool pick = solve(ind + 1, target - nums[ind], nums);

        return (pick || notPick);
    }

    bool checkSubsequenceSum(vector<int> &nums, int k)
    {
        // your code goes here
        return solve(0, k, nums);
    }
};