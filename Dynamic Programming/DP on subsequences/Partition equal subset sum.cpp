class Solution{
private:
    bool f(int ind, int target, vector<int> &arr)
    {
        if(target == 0)
            return true;
        if(ind == 0)
            return (arr[ind] == target);
        
        bool notPick = f(ind - 1, target, arr);

        bool pick = f(ind - 1, target - arr[ind], arr);

        return (pick || notPick);
    }
public:
    bool equalPartition(int n, vector<int> arr) {
        int totalSum = 0;
        for(auto i : arr)
            totalSum += i;
        
        if(totalSum % 2)
            return false;
        
        return f(n - 1, totalSum/2, arr);
    }
};

//Memoization
class Solution{
private:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;

        if(ind == 0)
            return (arr[ind] == target);
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        bool notPick = f(ind - 1, target, arr, dp);

        bool pick = false;
        if(target >= arr[ind])
            pick = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (pick || notPick);
    }
public:
    bool equalPartition(int n, vector<int> arr) {
        int totalSum = 0;
        for(auto i : arr)
            totalSum += i;
        
        if(totalSum % 2)
            return false;

        vector<vector<int>> dp(n, vector<int>(totalSum/2 + 1, -1));
        
        return f(n - 1, totalSum/2, arr, dp);
    }
};

//Tabulation
class Solution{
public:
    bool equalPartition(int n, vector<int> arr) {
        int totalSum = 0;
        for(auto i : arr)
            totalSum += i;
        
        if(totalSum % 2)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(totalSum/2 + 1, 0));

        for(int ind = 0; ind < n;ind++)
        {
            dp[ind][0] = true;
        }

        dp[0][arr[0]] = true;

        for(int ind = 1; ind < n;ind++)
        {
            for(int target = 0; target <= totalSum/2; target++)
            {
                bool notPick = dp[ind - 1][target];

                bool pick = false;
                if(target >= arr[ind])
                    pick = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = (pick || notPick);
            }
        }
        
        return dp[n - 1][totalSum/2];
    }
};
