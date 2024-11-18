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

//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini =INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        //Base case
        for(int i = 0;i < m;i++)
        {
            dp[0][i] = matrix[0][i]; 
        }

        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int up = INT_MAX, leftDiagonal = INT_MAX, rightDiagonal = INT_MAX;
                if(i > 0)
                    up = matrix[i][j] + dp[i- 1][j];
                if(i > 0 && j > 0)
                    leftDiagonal = matrix[i][j] + dp[i - 1][j - 1];
                if(i > 0 && j < m - 1)
                    rightDiagonal = matrix[i][j] + dp[i - 1][j + 1];
                
                dp[i][j] = min({up, leftDiagonal, rightDiagonal});
            }
        }

        for(int j = 0;j < m;j++)
        {
            int ans = dp[n - 1][j];
            mini = min(mini, ans);
        }
        return mini;
    }
};

//Space Optimized
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini =INT_MAX;
        vector<int> prev(m,-1);
        
        //Base case
        for(int i = 0;i < m;i++)
        {
            prev[i] = matrix[0][i]; 
        }
        vector<int> temp(m, 0);
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int up = INT_MAX, leftDiagonal = INT_MAX, rightDiagonal = INT_MAX;
                if(i > 0)
                    up = matrix[i][j] + prev[j];
                if(i > 0 && j > 0)
                    leftDiagonal = matrix[i][j] + prev[j - 1];
                if(i > 0 && j < m - 1)
                    rightDiagonal = matrix[i][j] + prev[j + 1];
                
                temp[j] = min({up, leftDiagonal, rightDiagonal});
            }
            prev = temp;
        }

        for(int j = 0;j < m;j++)
        {
            int ans = prev[j];
            mini = min(mini, ans);
        }
        return mini;
    }
};
