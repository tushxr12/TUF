class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int maxi = 0;
        int mini = arr[0];
        for(int i = 1;i < n;i++)
        {
            int currProfit = arr[i] - mini;
            maxi = max(maxi, currProfit);
            mini = min(mini, arr[i]);
        }
        return maxi;
    }
};

