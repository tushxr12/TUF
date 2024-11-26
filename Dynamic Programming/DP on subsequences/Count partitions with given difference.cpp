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
