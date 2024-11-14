//Memoization
class Solution {
private:
    int f(int ind, vector<int> &heights, vector<int> &dp)
    {
        if(ind == 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

        int right = INT_MAX;
        if(ind > 1)
        {
            right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
        }

        return dp[ind] = min(left, right);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n + 1,-1);
        return f(n - 1, heights, dp);
    }
};

//Tabulation
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n + 1,-1);
        dp[0] = 0;
        for(int i = 1;i < n;i++)
        {
            int firstStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int secondStep = INT_MAX;
            if(i > 1)
                secondStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);

            dp[i] = min(firstStep, secondStep);
        }
        return dp[n - 1];
    }
};

//Space Optimized Approach
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev1 = 0, prev2= 0;
        for(int i = 1;i < n;i++)
        {
            int firstStep = prev1 + abs(heights[i] - heights[i - 1]);
            int secondStep = INT_MAX;
            if(i > 1)
                secondStep = prev2 + abs(heights[i] - heights[i - 2]);

            int curr = min(firstStep, secondStep);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
