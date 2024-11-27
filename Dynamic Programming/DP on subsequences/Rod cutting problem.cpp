//Recursion
class Solution{
  private:
    int f(int ind,int n, vector<int> &prices)
    {
        if(ind == 0)
        {
            return n*prices[0];
        }

        int notTake = f(ind - 1,n,prices);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(rodLength <= n){
          take = prices[ind] + f(ind,n - rodLength,prices);
        }
        return max(take, notTake);
    }
  public:
    int rodCutting(vector<int> price, int n) {
        return f(n - 1,n,price);
    }
};
