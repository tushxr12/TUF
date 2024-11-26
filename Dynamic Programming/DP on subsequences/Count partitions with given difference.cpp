//Recursion
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int modulo = 1e9 + 7;
  private:
  int f(int ind,int k,vector<int> &arr)
  {
      if(k == 0)
        return 1;
      
      if(ind == 0)
      {
        return arr[0] == k;
      }

      int notPick = f(ind - 1,k,arr);

      int pick = 0;
      if(k >= arr[ind])
        pick = f(ind - 1,k - arr[ind], arr);
      
      return (pick + notPick)%modulo;
  }
  public:
  int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for(auto i : arr){
          totalSum += i;
        }

        return f(n -1, (totalSum - diff)/2, arr);
    }
};

//Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int modulo = 1e9 + 7;
  private:
  int f(int ind,int k,vector<int> &arr, vector<vector<int>> &dp)
  {
      if(k == 0)
        return 1;
      
      if(ind == 0)
      {
        return arr[0] == k;
      }

      if(dp[ind][k] != -1)
        return dp[ind][k];

      int notPick = f(ind - 1,k,arr, dp);

      int pick = 0;
      if(k >= arr[ind])
        pick = f(ind - 1,k - arr[ind], arr, dp);
      
      return dp[ind][k] =  (pick + notPick)%modulo;
  }
  public:
  int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for(auto i : arr){
          totalSum += i;
        }

        int reqSum = (totalSum - diff)/2;
        vector<vector<int>> dp(n, vector<int>(reqSum + 1,-1));
        return f(n -1, reqSum, arr, dp);
    }
};

//Tabulation
#include <bits/stdc++.h>
using namespace std;

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
};
