//Recursion
class Solution {
private:
    int f(int i,int j)
    {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        int up = f(i - 1,j);
        int left = f(i, j -1);
        return (up + left);
    }
public:
    int uniquePaths(int n, int m) {
        return f(n - 1,m - 1);
    }
};

//Memoization
class Solution {
private:
    int f(int i,int j,vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = f(i - 1,j,dp);
        int left = f(i, j -1,dp);
        return dp[i][j] = (up + left);
    }
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1,m - 1,dp);
    }
};

//Tabulation
class Solution {
private:
    int f(int i,int j,vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = f(i - 1,j,dp);
        int left = f(i, j -1,dp);
        return dp[i][j] = (up + left);
    }
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // dp[0][0] = 1;
        for(int i = 0;i <n;i++)
        {
            for(int j = 0;j <m;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i > 0)
                    up = dp[i - 1][j];
                if(j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[n - 1][m - 1];
    }
};

//Space Optimization
class Solution {
private:
    int f(int i,int j,vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = f(i - 1,j,dp);
        int left = f(i, j -1,dp);
        return dp[i][j] = (up + left);
    }
public:
    int uniquePaths(int n, int m) {
        vector<int> prev(n,0);
        // dp[0][0] = 1;
        for(int i = 0;i <n;i++)
        {
            vector<int> temp(m, 0);
            for(int j = 0;j <m;j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i > 0)
                    up = prev[j];
                if(j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[m - 1];
    }
};