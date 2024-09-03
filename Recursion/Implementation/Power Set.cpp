// Optimal
class Solution
{
public:
    void solve(int ind, vector<vector<int>> &ans, vector<int> &ls, vector<int> &nums)
    {
        if (ind == nums.size())
        {
            ans.push_back(ls);
            return;
        }

        // Non Pick
        solve(ind + 1, ans, ls, nums);

        // Pick
        ls.push_back(nums[ind]);
        solve(ind + 1, ans, ls, nums);
        ls.pop_back();
    }

    vector<vector<int>> powerSet(vector<int> &nums)
    {
        // your code goes here
        vector<vector<int>> ans;
        vector<int> ls;
        solve(0, ans, ls, nums);
        return ans;
    }
};