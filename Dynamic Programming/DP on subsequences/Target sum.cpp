//Tabulation
class Solution {
  int modulo = 1e9 + 7;
  public:
  int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for(auto i : arr){
          totalSum += i;
        }
        if(totalSum - diff < 0 || (totalSum - diff) %2){
          return 0;
        }
        int reqSum = (totalSum - diff)/2;
        vector<vector<int>> dp(n, vector<int>(reqSum + 1,0));
        for(int ind = 0;ind < n;ind++)
          dp[ind][0] = 1;

        if(reqSum >= arr[0])
          dp[0][arr[0]] = 1;

        for(int ind = 1; ind < n;ind++)
        {
          for(int k = 1;k <= reqSum;k++)
          {
              int notPick = dp[ind - 1][k];

              int pick = 0;
              if(k >= arr[ind])
                pick = dp[ind - 1][k - arr[ind]];
              
              dp[ind][k] =  (pick + notPick)%modulo;
          }
        }
        return dp[n -1][reqSum];
    }
  
    public:
    int targetSum(int n, int target, vector<int>& nums) {
      return countPartitions(n, target, nums);
  }
};
