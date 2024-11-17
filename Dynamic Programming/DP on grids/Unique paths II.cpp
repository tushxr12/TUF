//Recursion
class Solution {
private:
    int f(int i,int j, vector<vector<int>> &matrix)
    {
        if(i == 0 && j == 0 && matrix[i][j] != 1)
        {
            return 1;
        }
        if(i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;
        
        int up = f(i - 1,j,matrix);
        int left = f(i, j - 1, matrix);

        return (up + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        return f(n - 1,m - 1,matrix);
    }
};

//Memoization
class Solution {
private:
    int f(int i,int j, vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0 && matrix[i][j] != 1)
        {
            return 1;
        }
        if(i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = f(i - 1,j,matrix,dp);
        int left = f(i, j - 1, matrix,dp);

        return dp[i][j] = (up + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n - 1,m - 1,matrix,dp);
    }
};
