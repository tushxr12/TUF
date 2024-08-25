// Brute
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> positives, negatives;
        for (auto i : nums)
        {
            if (i >= 0)
                positives.push_back(i);
            else
                negatives.push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            ans.push_back(positives[i]);
            ans.push_back(negatives[i]);
        }
        return ans;
    }
};

// Optimal (In one pass)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};