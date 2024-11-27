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
