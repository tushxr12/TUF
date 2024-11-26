//Recursion
class Solution
{
    private:
    int f(int ind, int w, vector<int> &wt, vector<int> &val)
    {   
        if(ind == 0)
        {
            if(wt[0] <= w)
                return val[0];
            return 0;
        }

        int notTake = f(ind - 1, w, wt, val);
        int take = INT_MIN;

        if(wt[ind] <= w)
        {
            take = val[ind] + f(ind - 1,w - wt[ind], wt, val);
        }

        return max(take, notTake);
    }
    public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        return f(n - 1,W,wt,val);
    }
};

//Memoization
class Solution
{
    private:
    int f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
    {   
        if(ind == 0)
        {
            if(wt[0] <= w)
                return val[0];
            return 0;
        }

        if(dp[ind][w] != -1)
            return dp[ind][w];

        int notTake = f(ind - 1, w, wt, val, dp);
        int take = INT_MIN;

        if(wt[ind] <= w)
        {
            take = val[ind] + f(ind - 1,w - wt[ind], wt, val, dp);
        }

        return dp[ind][w] = max(take, notTake);
    }
    public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1,-1));
        return f(n - 1,W,wt,val,dp);
    }
};
