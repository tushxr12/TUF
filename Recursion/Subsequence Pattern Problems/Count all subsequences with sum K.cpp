class Solution
{
public:
    int solve(int ind, int target, vector<int> &nums)
    {
        if (target == 0)
            return 1;

        if (target < 0 || ind == nums.size())
            return 0;

        // Not Pick
        int notPick = solve(ind + 1, target, nums);

        // Pick
        int pick = solve(ind + 1, target - nums[ind], nums);

        return (pick + notPick);
    }

    int countSubseqenceWithTargetSum(vector<int> &nums, int k)
    {
        // your code goes here
        return solve(0, k, nums);
    }
};