class Solution
{
public:
    int largestElement(vector<int> &nums)
    {
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
                largest = nums[i];
        }
        return largest;
    }
};