class Solution{
private:
    int f(int ind,int buy,vector<int> &arr)
    {
        if(ind == arr.size())
        {
            return 0;
        }

        long profit = 0;
        if(buy)
        {
            profit = max(-arr[ind] + f(ind + 1,0,arr), 0 + f(ind + 1,1,arr));
        }
        else
        {
            profit = max(arr[ind] + f(ind + 1,1,arr), 0 + f(ind + 1,0,arr));
        }
        return profit;
    }
public:
    int stockBuySell(vector<int> arr, int n){
        return f(0,1,arr);
    }   
};

//Memoization
class Solution{
private:
    int f(int ind,int buy,vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == arr.size())
        {
            return 0;
        }

        if(dp[ind][buy] != -1)  
            return dp[ind][buy];
        
        long profit = 0;
        if(buy)
        {
            profit = max(-arr[ind] + f(ind + 1,0,arr,dp), 0 + f(ind + 1,1,arr,dp));
        }
        else
        {
            profit = max(arr[ind] + f(ind + 1,1,arr,dp), 0 + f(ind + 1,0,arr,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int stockBuySell(vector<int> arr, int n){
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return f(0,1,arr,dp);
    }   
};

