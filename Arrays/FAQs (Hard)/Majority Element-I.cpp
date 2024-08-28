// Better
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mpp;
        int ans = 0;
        for (auto i : nums)
        {
            mpp[i]++;
        }
        for (auto i : mpp)
        {
            if (i.second > nums.size() / 2)
            {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};

// Optimal (Using Moore Voting algorithm)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, el;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return el;
    }
};