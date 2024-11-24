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
