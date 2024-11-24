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
