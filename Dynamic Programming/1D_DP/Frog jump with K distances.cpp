class Solution {
private:
    int f(int ind, vector<int> &heights, vector<int> &dp,int k)
    {
        if(ind == 0)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int minSteps = INT_MAX; 
        for(int j = 1;j <= k;j++)
        {
            if(ind - j >= 0)
            {  
                int jump = f(ind - j, heights, dp, k) + abs(heights[ind] - heights[ind - j]);
                minSteps = min(minSteps, jump);
            }
        }
        return dp[ind] = minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return f(n - 1, heights, dp, k);
    }
};
