class Solution {
public:
    void solve(int ind,vector<vector<int>> &ans,vector<int>&ds,vector<int> &nums)
    {
        if(ind == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        //Pick
        ds.push_back(nums[ind]);
        solve(ind + 1,ans,ds,nums);
        ds.pop_back();

        //Not Pick
        for(int i = ind + 1;i < nums.size();i++)
        {
            if(nums[i] != nums[ind])
            {
                solve(i,ans,ds,nums);
                return;
            }
        }
        
        // if nums = [1,2,2,2]
        solve(nums.size(), ans,ds, nums);
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,ans,ds,nums);
        return ans;
    }
};