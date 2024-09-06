class Solution {
public:
    void solve(int ind, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        if(target < 0 || ind == nums.size())
            return;
        
        //Not Pick
        for(int i = ind;i < nums.size();i++)
        {
            if(nums[i] != nums[ind])
            {
                solve(i,target,nums,ans,ds);
                break;
            }
        }

        //Pick
        ds.push_back(nums[ind]);
        solve(ind + 1,target-nums[ind],nums,ans,ds);
        ds.pop_back();
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,candidates,ans,ds);
        return ans;
    }
};