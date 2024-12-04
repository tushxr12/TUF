class Solution{
  private:
  int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
  {
    if(ind1 < 0 || ind2 < 0)
      return 0;

    if(dp[ind1][ind2] != -1)
      return dp[ind1][ind2];

    //If match
    if(s1[ind1] == s2[ind2])
    {
      return 1 + f(ind1 - 1,ind2 - 1, s1, s2, dp);
    }

    //If Not match
    return dp[ind1][ind2] = max(f(ind1 -1,ind2,s1 ,s2, dp) , f(ind1, ind2 - 1, s1, s2, dp));
  }
  int lcs(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(str1.size() - 1, str2.size() - 1, str1, str2, dp);
  }
  public:
    int longestPalinSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(t,s);
    }
};

//Tabulation
class Solution{
  private:
    int lcs(string s1, string s2) {
      int n1 = s1.size(), n2 = s2.size();
      vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

      for(int ind1 = 0; ind1 <= n1;ind1++){
        dp[ind1][0] = 0;
      }

      for(int ind2 = 0;ind2 <= n2;ind2++){
        dp[0][ind2] = 0;
      }

      for(int ind1 = 1;ind1 <= n1;ind1++)
      {
        for(int ind2 = 1;ind2 <= n2;ind2++)
        {
          if(s1[ind1 - 1] == s2[ind2 - 1])
          {
            dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
          }
          else
            dp[ind1][ind2] = max(dp[ind1 -1][ind2], dp[ind1][ind2 - 1]);
        }
      }

      return dp[n1][n2];
    }
  public:
    int longestPalinSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(t,s);
    }
};

//Space optmization
class Solution{
  private:
    int lcs(string s1, string s2) {
      int n1 = s1.size(), n2 = s2.size();
      vector<int> curr(n2 + 1, 0), prev(n2 + 1,0);

      for(int ind2 = 0;ind2 <= n2;ind2++){
        prev[ind2] = 0;
      }

      for(int ind1 = 1;ind1 <= n1;ind1++)
      {
        for(int ind2 = 1;ind2 <= n2;ind2++)
        {
          if(s1[ind1 - 1] == s2[ind2 - 1])
          {
            curr[ind2] = 1 + prev[ind2 - 1];
          }
          else
            curr[ind2] = max(prev[ind2], curr[ind2 - 1]);
        }
        prev = curr;
      }

      return prev[n2];
    }
  public:
    int longestPalinSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(t,s);
    }
};
