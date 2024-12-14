//Recursion
class Solution {
  private:
    int f(int i,int j, string s1, string s2)
    {

      if(i < 0 && j < 0) return true;
      if(i < 0 && j >= 0) return false;
      if(j < 0 && i >=0)
      {
        for(int ii=0;ii<=i;ii++)
          if(s1[ii] != '*')
            return false;
        
        return true;
      }

      if(s1[i] == s2[j] || s1[i] == '?')
        return f(i - 1,j - 1,s1,s2);
      if(s1[i] == '*')
        return f(i - 1,j,s1,s2) || f(i, j -1,s1,s2);
      return false;
    }
  public:
  bool wildCard(string str, string pat) {
    int n = str.size(), m = pat.size();
    return f(n-1, m-1, str, pat);
  }
};

//Memoization
class Solution {
  private:
    int f(int i,int j, string s1, string s2, vector<vector<int>> &dp)
    {

      if(i < 0 && j < 0) return true;
      if(i < 0 && j >= 0) return false;
      if(j < 0 && i >=0)
      {
        for(int ii=0;ii<=i;ii++)
          if(s1[ii] != '*')
            return false;
        
        return true;
      }
      if(dp[i][j] != -1)
        return dp[i][j];
      if(s1[i] == s2[j] || s1[i] == '?')
        return dp[i][j] = f(i - 1,j - 1,s1,s2,dp);
      if(s1[i] == '*')
        return dp[i][j] = f(i - 1,j,s1,s2,dp) || f(i, j -1,s1,s2,dp);
      return false;
    }
  public:
  bool wildCard(string str, string pat) {
    int n = str.size(), m = pat.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1, str, pat,dp);
  }
};

//Tabulation
class Solution {
  public:
  bool wildCard(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for(int j = 1;j <= m;j++)
      dp[0][j] = false;
    
    for(int i = 1;i <= n;i++)
    {
      bool fl = true;
      for(int ii = 1; ii <= i;ii++)
      {
        if(s1[ii-1] != '*')
        {
          fl = false;
          break;
        }
      }
      dp[i][0] = fl;
    }

    for(int i = 1;i <= n;i++)
    {
      for(int j = 1;j <= m;j++)
      {
          if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            dp[i][j] = dp[i - 1][j - 1];
          else if(s1[i - 1] == '*')
            dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
          else
            dp[i][j] = false;
      }
    }
    return dp[n][m];
  }
};
