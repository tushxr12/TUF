//Brute force
class Solution
{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
       vector<int> ans(n);
       for(int i = 0;i < n;i++)
       {
         int cnt = 0;
         for(int j = i;j >= 0;j--)
         {
            if(arr[j] <= arr[i])
                cnt++;
            else
                break;
         }
         ans[i] = cnt;
       }
       return ans;
    }
};
