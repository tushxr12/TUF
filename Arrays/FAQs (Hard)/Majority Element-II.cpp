// Better
class Solution
{
public:
    vector<int> majorityElementTwo(vector<int> &nums)
    {
        vector<int> ans;
        map<int, int> mpp;
        for (auto i : nums)
            mpp[i]++;
        for (auto i : mpp)
        {
            if (i.second > nums.size() / 3)
                ans.push_back(i.first);
        }
        return ans;
    }
};

// Optimal (Modification of Moore Voting Algorithm)
class Solution
{
public:
    vector<int> majorityElementTwo(vector<int> &nums)
    {
        vector<int> ans;
        int el1 = -1, el2 = -1;
        int cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != el2)
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1)
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i])
            {
                cnt1++;
            }
            else if (el2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (auto i : nums)
        {
            if (i == el1)
                cnt1++;
            else if (i == el2)
                cnt2++;
        }
        if (cnt1 >= ((n / 3) + 1))
            ans.push_back(el1);
        if (cnt2 >= ((n / 3) + 1))
            ans.push_back(el2);
        return ans;
    }
};