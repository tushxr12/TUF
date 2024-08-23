class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int oneCount = 0, maxOneCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                oneCount++;
            }
            else
            {
                oneCount = 0;
            }
            maxOneCount = max(maxOneCount, oneCount);
        }
        return maxOneCount;
    }
};