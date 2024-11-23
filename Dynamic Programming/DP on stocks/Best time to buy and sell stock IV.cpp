//Recursion
class Solution{
private:
    int f(int ind,int tranNo, int n, int k, vector<int> &arr)
    {
        if(ind == n || tranNo == 2*k)
            return 0;
        
        //Buy
        if(tranNo % 2 == 0)
        {
            return max(-arr[ind] + f(ind + 1,tranNo + 1,n,k,arr) , 0 + f(ind + 1,tranNo,n,k,arr));
        }

        //Sell
        return max(arr[ind] + f(ind + 1,tranNo + 1,n,k,arr) , 0 + f(ind + 1,tranNo,n,k,arr));
    }
public:
    int stockBuySell(vector<int> arr, int n, int k){
        return f(0,0,n,k,arr);
    }
};

//Memoization
class Solution{
private:
    int f(int ind,int tranNo, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == n || tranNo == 2*k)
            return 0;
        
        if(dp[ind][tranNo] != -1)
            return dp[ind][tranNo];
        
        //Buy
        if(tranNo % 2 == 0)
        {
            return dp[ind][tranNo] = max(-arr[ind] + f(ind + 1,tranNo + 1,n,k,arr,dp) , 0 + f(ind + 1,tranNo,n,k,arr,dp));
        }

        //Sell
        return dp[ind][tranNo] = max(arr[ind] + f(ind + 1,tranNo + 1,n,k,arr,dp) , 0 + f(ind + 1,tranNo,n,k,arr,dp));
    }
public:
    int stockBuySell(vector<int> arr, int n, int k){
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return f(0,0,n,k,arr,dp);
    }
};

//Tabulation
class Solution{
public:
    int stockBuySell(vector<int> arr, int n, int k){
        vector<vector<int>> dp(n + 1, vector<int>(2*k + 1, 0));

        for(int ind = n - 1; ind >= 0;ind--)
        {
            for(int tranNo = 2*k - 1; tranNo >= 0;tranNo--)
            {
                //Buy
                if(tranNo % 2 == 0)
                {
                    dp[ind][tranNo] = max(-arr[ind] + dp[ind + 1][tranNo + 1] , 0 + dp[ind + 1][tranNo]);
                }
                else
                {
                    //Sell
                    dp[ind][tranNo] = max(arr[ind] + dp[ind + 1][tranNo + 1] , 0 + dp[ind + 1][tranNo]);
                } 
            }
        }
        return dp[0][0];
    }
};

//Space optimization
class Solution{
public:
    int stockBuySell(vector<int> arr, int n, int k){
        vector<int> front(2*k + 1, 0);
        vector<int> curr(2*k +1,0);

        for(int ind = n - 1; ind >= 0;ind--)
        {
            for(int tranNo = 2*k - 1; tranNo >= 0;tranNo--)
            {
                //Buy
                if(tranNo % 2 == 0)
                {
                    curr[tranNo] = max(-arr[ind] + front[tranNo + 1] , 0 + front[tranNo]);
                }
                else
                {
                    //Sell
                    curr[tranNo] = max(arr[ind] + front[tranNo + 1] , 0 + front[tranNo]);
                } 
            }
            front = curr;
        }
        return front[0];
    }
};
