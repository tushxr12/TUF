class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zeroesCount = 0;
        vector<int> temp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                temp.push_back(nums[i]);
            else
                zeroesCount++;
        }
        while (zeroesCount--)
            temp.push_back(0);
        nums = temp;
    }
};