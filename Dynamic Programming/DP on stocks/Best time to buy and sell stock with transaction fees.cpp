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
