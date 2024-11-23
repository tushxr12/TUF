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
