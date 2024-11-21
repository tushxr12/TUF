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
