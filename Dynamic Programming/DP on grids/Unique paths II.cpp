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

//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[0][0] == 1 || matrix[n - 1][m - 1] == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(i == 0 && j == 0 && dp[i][j] != 1)
                {
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0, left = 0;
                if(i > 0 && matrix[i - 1][j] != 1)
                {
                    up = dp[i - 1][j];
                }

                if(j > 0 && matrix[i][j - 1] != 1)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
        return dp[n-1][m-1];
    }
};

//Space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[0][0] == 1 || matrix[n - 1][m - 1] == 1)
            return 0;
        
        vector<int> prev(n,-1);
        for(int i = 0;i < n;i++)
        {
            vector<int> temp(m, -1);
            for(int j = 0;j < m;j++)
            {
                if(i == 0 && j == 0 && temp[j] != 1)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0, left = 0;
                if(i > 0 && matrix[i - 1][j] != 1)
                {
                    up = prev[j];
                }

                if(j > 0 && matrix[i][j - 1] != 1)
                {
                    left = temp[j - 1];
                }
                temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[m-1];
    }
};
