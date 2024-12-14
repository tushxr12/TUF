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
