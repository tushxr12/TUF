//Recursion
class Solution {
  private:
    int f(int i,int j, string s1, string s2)
    {
      if(i < 0)
        return j + 1;
      if(j < 0)
        return i + 1;
      if(s1[i] == s2[j])
        return 0 + f(i - 1,j - 1,s1,s2);
      int insert = 1 + f(i,j - 1,s2,s2);
      int deletee = 1 + f(i - 1,j,s1,s2);
      int replace = 1 + f(i - 1,j - 1,s1,s2);
      return min({insert, deletee, replace});
    }
  public:
    int editDistance(string s1, string s2) {
      int n = s1.size(), m = s2.size();
      return f(n - 1,m-1,s1,s2);
    }
};

//Memoization
class Solution {
  private:
    int f(int i,int j, string &s1, string &s2,vector<vector<int>> &dp)
    {
      if(i < 0)
        return j + 1;

      if(j < 0)
        return i + 1;

      if(dp[i][j] != -1)
        return dp[i][j];

      if(s1[i] == s2[j])
        return dp[i][j] = f(i - 1,j - 1,s1,s2,dp);
      
      return dp[i][j] = 1 +  min({f(i,j - 1,s2,s2,dp), f(i - 1,j,s1,s2,dp), f(i - 1,j - 1,s1,s2,dp)});
    }
  public:
    int editDistance(string s1, string s2) {
      int n = s1.size(), m = s2.size();
      vector<vector<int>> dp(n, vector<int>(m,-1));
      return f(n - 1,m-1,s1,s2,dp);
    }
};
