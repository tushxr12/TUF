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

//Tabulation
class Solution
{
    public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1,0));

        for(int i = wt[0]; i<=W;i++)
        {
            dp[0][i] = val[0];
        }

        for(int ind = 1;ind < n;ind++)
        {
            for(int w=0; w<=W;w++)
            {
                int notTake = dp[ind -1][w];
                int take = INT_MIN;

                if(wt[ind] <= w)
                {
                    take = val[ind] + dp[ind - 1][w - wt[ind]];
                }

                dp[ind][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }
};

//Space optmization
class Solution
{
    public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> curr(W + 1,0), prev(W + 1,0);

        for(int i = wt[0]; i<=W;i++)
        {
            prev[i] = val[0];
        }

        for(int ind = 1;ind < n;ind++)
        {
            for(int w=0; w<=W;w++)
            {
                int notTake = prev[w];
                int take = INT_MIN;

                if(wt[ind] <= w)
                {
                    take = val[ind] + prev[w - wt[ind]];
                }

                curr[w] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[W];
    }
};
