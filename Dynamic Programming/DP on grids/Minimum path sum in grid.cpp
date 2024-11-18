//Recursion
class Solution {
private:
    int f(int i,int j, vector<vector<int>> &matrix)
    {
        if(j < 0 || j >= matrix[0].size())
            return 1e9;
        if(i == 0)
            return matrix[0][j];
        
        int up = matrix[i][j] + f(i - 1,j,matrix);
        int leftDiagonal = matrix[i][j] + f(i - 1,j - 1,matrix);
        int rightDiagonal = matrix[i][j] + f(i - 1,j + 1,matrix);

        return min({up, leftDiagonal, rightDiagonal});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini =INT_MAX;
        for(int j = 0;j < m;j++)
        {
            int ans = f(n - 1,j,matrix);
            mini = min(mini, ans);
        }
        return mini;
    }
};

//Memoization
class Solution {
private:
    int f(int i,int j, vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        if(j < 0 || j >= matrix[0].size())
            return 1e9;
        if(i == 0)
            return matrix[0][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = matrix[i][j] + f(i - 1,j,matrix,dp);
        int leftDiagonal = matrix[i][j] + f(i - 1,j - 1,matrix,dp);
        int rightDiagonal = matrix[i][j] + f(i - 1,j + 1,matrix,dp);

        return dp[i][j] = min({up, leftDiagonal, rightDiagonal});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini =INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int j = 0;j < m;j++)
        {
            int ans = f(n - 1,j,matrix,dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};
