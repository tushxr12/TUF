//Recursion
class Solution {
private:
    int f(int i,int j1,int j2,int r,int c, vector<vector<int>> &matrix)
    {
        if(j1 < 0 || j2 <= 0|| j1 >= c || j2 >= c)
        {
            return -1e8;
        }

        if(i == r -1)
        {
            if(j1 == j2)    
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }

        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= +1;dj1++)
        {
            for(int dj2 = -1;dj2 <= +1;dj2++)
            {
                int val = 0;
                if(j1 == j2)
                    val = matrix[i][j1];
                else
                    val = matrix[i][j1] + matrix[i][j2];
                val += f(i + 1,j1+dj1,j2+dj2,r,c,matrix);
                maxi = max(maxi, val);
            }
        }
        return maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        return f(0,0,c - 1,r,c,matrix);
    }
};

//Memoization
class Solution {
private:
    int f(int i,int j1,int j2,int r,int c, vector<vector<int>> &matrix,vector<vector<vector<int>>> &dp)
    {
        if(j1 < 0 || j2 <= 0|| j1 >= c || j2 >= c)
        {
            return -1e8;
        }
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        if(i == r -1)
        {
            if(j1 == j2)    
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }

        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= +1;dj1++)
        {
            for(int dj2 = -1;dj2 <= +1;dj2++)
            {
                int val = 0;
                if(j1 == j2)
                    val = matrix[i][j1];
                else
                    val = matrix[i][j1] + matrix[i][j2];
                val += f(i + 1,j1+dj1,j2+dj2,r,c,matrix,dp);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1)));
        return f(0,0,c - 1,r,c,matrix,dp);
    }
};

//Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        
        for(int j1= 0; j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1 == j2)
                    dp[n-1][j1][j2] = matrix[n-1][j1];
                else
                    dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
            }
        }
        
        for(int i = n - 2;i >= 0;i--)
        {
            for(int j1 = 0; j1 < m;j1++)
            {
                for(int j2 = 0; j2 <m;j2++)
                {
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= +1;dj1++)
                    {
                        for(int dj2 = -1;dj2 <= +1;dj2++)
                        {
                            int val = 0;
                            if(j1 == j2)
                                val = matrix[i][j1];
                            else
                                val = matrix[i][j1] + matrix[i][j2];
                            if(j1 + dj1 >= 0 && j1+dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                                val += dp[i + 1][j1+dj1][j2+dj2];
                            else
                                val += (-1e8);
                            maxi = max(maxi, val);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};

//Space Optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> front(m, vector<int>(m,0));
        vector<vector<int>> curr(m, vector<int>(m,0));   
        for(int j1= 0; j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1 == j2)
                    front[j1][j2] = matrix[n-1][j1];
                else
                    front[j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
            }
        }
        
        for(int i = n - 2;i >= 0;i--)
        {
            for(int j1 = 0; j1 < m;j1++)
            {
                for(int j2 = 0; j2 <m;j2++)
                {
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= +1;dj1++)
                    {
                        for(int dj2 = -1;dj2 <= +1;dj2++)
                        {
                            int val = 0;
                            if(j1 == j2)
                                val = matrix[i][j1];
                            else
                                val = matrix[i][j1] + matrix[i][j2];
                            if(j1 + dj1 >= 0 && j1+dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                                val += front[j1+dj1][j2+dj2];
                            else
                                val += (-1e8);
                            maxi = max(maxi, val);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m-1];
    }
};
