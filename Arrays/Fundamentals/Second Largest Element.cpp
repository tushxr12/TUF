class Solution
{
public:
    int secondLargestElement(vector<int> &nums)
    {
        int largest = INT_MIN, second_largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                largest = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (second_largest < nums[i] && nums[i] < largest)
                second_largest = nums[i];
        }

        if (second_largest == INT_MIN)
            return -1;
        return second_largest;
    }
};