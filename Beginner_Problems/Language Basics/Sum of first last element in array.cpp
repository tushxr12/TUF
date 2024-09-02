class Solution
{
public:
    int sumOfFirstAndLast(vector<int> &nums)
    {
        int n = nums.size();
        int reqSum = nums[0] + nums[n - 1];
        return reqSum;
    }
};