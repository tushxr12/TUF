//Recursion
class Solution {
private:
    int f(int i,int j,vector<vector<int>> &triangle)
    {
        if(i == triangle.size() - 1)
        {
            return triangle[triangle.size() - 1][j];
        }

        int down = triangle[i][j] + f(i + 1,j,triangle);
        int rightDiagonal = triangle[i][j] + f(i + 1,j + 1,triangle);

        return min(down, rightDiagonal);
    }
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        return f(0,0,triangle);
    }
};

//Memoization
class Solution {
private:
    int f(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1)
            return dp[i][j];  

        if(i == n - 1)
        {
            return triangle[i][j];
        }
          

        int down = triangle[i][j] + f(i + 1,j,n,triangle,dp);
        int rightDiagonal = triangle[i][j] + f(i + 1,j + 1,n,triangle,dp);

        return dp[i][j] = min(down, rightDiagonal);
    }
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,n,triangle,dp);
    }
};

//Tabulation
class Solution {
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int j = 0;j < n;j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for(int i = n - 2;i >= 0;i--)
        {
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int rightDiagonal = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, rightDiagonal);
            }
        }
        return dp[0][0];
    }
};

//Space Optimization
class Solution {
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,-1);

        for(int j = 0;j < n;j++)
        {
            front[j] = triangle[n - 1][j];
        }

        for(int i = n - 2;i >= 0;i--)
        {
            vector<int> temp(n,0);
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] +front[j];
                int rightDiagonal = triangle[i][j] + front[j + 1];

                temp[j] = min(down, rightDiagonal);
            }
            front = temp;
        }
        return front[0];
    }
};
