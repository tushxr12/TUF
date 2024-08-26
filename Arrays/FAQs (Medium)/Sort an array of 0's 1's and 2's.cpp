// Brute
class Solution
{
public:
    void sortZeroOneTwo(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }
};

// Better (Keep count of number of zero, one and twos)
class Solution
{
public:
    void sortZeroOneTwo(vector<int> &nums)
    {
        int n = nums.size(), zeroCount = 0, oneCount = 0, twoCount = 0;
        for (auto i : nums)
        {
            if (i == 0)
                zeroCount++;
            else if (i == 1)
                oneCount++;
            else
                twoCount++;
        }

        for (int i = 0; i < zeroCount; i++)
            nums[i] = 0;

        for (int i = zeroCount; i < zeroCount + oneCount; i++)
            nums[i] = 1;

        for (int i = zeroCount + oneCount; i < n; i++)
            nums[i] = 2;
    }
};

// Optimal (Dutch National Flag Algorithm)
class Solution
{
public:
    void sortZeroOneTwo(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};