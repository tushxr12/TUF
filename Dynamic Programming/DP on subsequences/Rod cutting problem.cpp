//Recursion
class Solution{
  private:
    int f(int ind,int n, vector<int> &prices)
    {
        if(ind == 0)
        {
            return n*prices[0];
        }

        int notTake = f(ind - 1,n,prices);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(rodLength <= n){
          take = prices[ind] + f(ind,n - rodLength,prices);
        }
        return max(take, notTake);
    }
  public:
    int rodCutting(vector<int> price, int n) {
        return f(n - 1,n,price);
    }
};

//Memoization
class Solution{
  private:
    int f(int ind,int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            return n*prices[0];
        }

        if(dp[ind][n] != -1)  
          return dp[ind][n];

        int notTake = f(ind - 1,n,prices,dp);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(rodLength <= n){
          take = prices[ind] + f(ind,n - rodLength,prices,dp);
        }
        return dp[ind][n] = max(take, notTake);
    }
  public:
    int rodCutting(vector<int> price, int n) {
      vector<vector<int>> dp(n, vector<int>(n + 1,-1));
      return f(n - 1,n,price,dp);
    }
};

//Space optimization
class Solution{
  public:
    int rodCutting(vector<int> price, int N) {
      vector<vector<int>> dp(N, vector<int>(N + 1,0));

      for(int ind = 0; ind <= N;ind++)
      {
        dp[0][ind] = ind*price[0];
      }

      for(int ind = 1;ind < N;ind++)
      {
        for(int n = 1; n <= N;n++)
        {
            int notTake = dp[ind - 1][n];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= n){
              take = price[ind] + dp[ind][n - rodLength];
            }
            dp[ind][n] = max(take, notTake);
        }
      }
      return dp[N - 1][N];
    }
};

//Space optimization
class Solution{
  public:
    int rodCutting(vector<int> price, int N) {
      vector<int> curr(N + 1,0), prev(N + 1,0);

      for(int ind = 0; ind <= N;ind++)
      {
        prev[ind] = ind*price[0];
      }

      for(int ind = 1;ind < N;ind++)
      {
        for(int n = 1; n <= N;n++)
        {
            int notTake = prev[n];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= n){
              take = price[ind] + curr[n - rodLength];
            }
            curr[n] = max(take, notTake);
        }
        prev = curr;
      }
      return prev[N];
    }
};
