//Recursion
class Solution{
private:
    int f(int ind, int buy, int cap, vector<int> &arr)
    {
        if(ind == arr.size() || cap == 0)
            return 0;

        if(buy == 1)
        {
            return max(-arr[ind] + f(ind + 1,0,cap,arr), 0 + f(ind + 1,1,cap,arr));
        }

        return max(arr[ind] + f(ind + 1,1,cap-1,arr) , 0 + f(ind + 1,0,cap,arr));
    }
public:
    int stockBuySell(vector<int> arr, int n){
        return f(0,1,2,arr);
    }
};

//Memoization
class Solution{
private:
    int f(int ind, int buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
    {
        if(ind == arr.size() || cap == 0)
            return 0;

        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if(buy == 1)
        {
            return max(-arr[ind] + f(ind + 1,0,cap,arr,dp), 0 + f(ind + 1,1,cap,arr,dp));
        }

        return dp[ind][buy][cap] = max(arr[ind] + f(ind + 1,1,cap-1,arr,dp) , 0 + f(ind + 1,0,cap,arr,dp));
    }
public:
    int stockBuySell(vector<int> arr, int n){
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,2,arr,dp);
    }
};

//Tabulation
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>> (2, vector<int>(3,0)));

        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1;buy++)
            {
                for(int cap = 1; cap <= 2;cap++)
                {
                    if(buy == 0)
                    {
                        dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap], -arr[ind] + dp[ind + 1][1][cap]);
                    }
                    if(buy == 1)
                    {
                        dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap], arr[ind] + dp[ind + 1][0][cap - 1]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};

//Space Optimization
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        vector<vector<int>> front(2,vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));

        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1;buy++)
            {
                for(int cap = 1; cap <= 2;cap++)
                {
                    if(buy == 0)
                    {
                        curr[buy][cap] = max(0 + front[0][cap], -arr[ind] + front[1][cap]);
                    }
                    if(buy == 1)
                    {
                        curr[buy][cap] = max(0 + front[1][cap], arr[ind] + front[0][cap - 1]);
                    }
                }
            }
            front = curr;
        }
        return front[0][2];
    }
};
