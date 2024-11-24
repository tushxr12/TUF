//Recursion
class Solution{   
private:
    bool f(int ind, vector<int> &arr, int target)
    {
        if(target == 0){
            return true;
        }

        if(ind == 0){
            return (arr[0] == target);
        }

        bool notTake = f(ind - 1, arr, target);
        bool take = false;
        if(target >= arr[ind]){
            take = f(ind - 1, arr, target - arr[ind]);
        }
        return (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return f(n - 1,arr,target);
    }
};

//Memoization
class Solution{   
private:
    bool f(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if(target == 0){
            return true;
        }

        if(ind == 0){
            return (arr[0] == target);
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = f(ind - 1, arr, target, dp);
        bool take = false;
        if(target >= arr[ind]){
            take = f(ind - 1, arr, target - arr[ind], dp);
        }
        return dp[ind][target] = (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1,-1));
        return f(n - 1,arr,target, dp);
    }
};

//Tabulation
class Solution{  
public:
    bool isSubsetSum(vector<int>arr, int t){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(t + 1,0));

        for(int ind = 0; ind < n;ind++)
        {
            dp[ind][0] = true;
        }

        dp[0][arr[0]] = true;

        for(int ind = 1; ind < n;ind++)
        {
            for(int target = 1; target <= t;target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if(target >= arr[ind]){
                    take = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = (take || notTake);
            }
        }

        return dp[n-1][t];
    }
};
