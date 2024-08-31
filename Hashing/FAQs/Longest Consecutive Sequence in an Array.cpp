// Brute
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        for (auto i : nums)
            if (target == i)
                return true;
        return false;
    }
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 1, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            int cnt = 1;

            while (search(nums, curr + 1) == true)
            {
                curr += 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

// Better
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int longest = 1, currCount = 1, lastSmaller = INT_MIN, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] - 1 == lastSmaller)
            {
                currCount++;
                lastSmaller = nums[i];
            }
            else if (nums[i] != lastSmaller)
            {
                currCount = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, currCount);
        }
        return longest;
    }
};

// Optimal
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 1, n = nums.size();
        if (!n)
            return 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto i : st)
        {
            if (st.find(i - 1) == st.end())
            {
                int cnt = 1;
                int x = i;
                while (st.find(x + 1) != st.end())
                {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
