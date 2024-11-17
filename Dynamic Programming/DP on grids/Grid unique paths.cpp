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
