//Recursion
class Solution{
private:
    int f(int ind,int buy,int fee,int n, vector<int> &arr)
    {
        if(ind == n)
            return 0;
        
        if(buy == 1)
        {
            return max(-arr[ind] + f(ind + 1,0,fee,n,arr) , 0 + f(ind + 1,1,fee,n,arr));
        }

        //Sell
        return max(arr[ind] - fee + f(ind + 1,1,fee,n,arr), 0 + f(ind + 1,0,fee,n,arr));
    }   
public:
    int stockBuySell(vector<int> arr, int n, int fee){
        return f(0,1,fee,n,arr);
    }
};

//Memoization
class Solution{
private:
    int f(int ind,int buy,int fee,int n, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == n)
            return 0;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        if(buy == 1)
        {
            return dp[ind][buy] =  max(-arr[ind] + f(ind + 1,0,fee,n,arr,dp) , 0 + f(ind + 1,1,fee,n,arr,dp));
        }

        //Sell
        return dp[ind][buy] = max(arr[ind] - fee + f(ind + 1,1,fee,n,arr,dp), 0 + f(ind + 1,0,fee,n,arr,dp));
    }   
public:
    int stockBuySell(vector<int> arr, int n, int fee){
        vector<vector<int>> dp(n + 1, vector<int>(2,-1));
        return f(0,1,fee,n,arr,dp);
    }
};

//Add tabulation
class Solution{
public:
    int stockBuySell(vector<int> arr, int n, int fee){
        vector<vector<int>> dp(n + 1, vector<int>(2,0));

        for(int ind = n- 1; ind >= 0;ind--)
        {
            for(int buy = 0; buy < 2;buy++)
            {
                if(buy == 1)
                {
                    //Buy
                    dp[ind][buy] =  max(-arr[ind] + dp[ind + 1][0] , 0 + dp[ind + 1][1]);
                }
                else
                {
                    //Sell
                    dp[ind][buy] = max(arr[ind] - fee + dp[ind + 1][1], 0 + dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};

//Space optimization
class Solution{
public:
    int stockBuySell(vector<int> arr, int n, int fee){
        vector<int> front(2,0);
        vector<int> curr(2,0);
        for(int ind = n- 1; ind >= 0;ind--)
        {
            for(int buy = 0; buy < 2;buy++)
            {
                if(buy == 1)
                {
                    //Buy
                    curr[buy] =  max(-arr[ind] + front[0] , 0 + front[1]);
                }
                else
                {
                    //Sell
                    curr[buy] = max(arr[ind] - fee + front[1], 0 + front[0]);
                }
            }
            front = curr;
        }

        return front[1];
    }
};
