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