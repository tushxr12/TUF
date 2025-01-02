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

//Optimal
class Solution
{
    private:
    vector<int> findPGE(vector<int> &arr, int n)
    {
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0;i < n;i++)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            
            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            
            st.push(i);
        }
        return pge;
    }
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
       vector<int> pge = findPGE(arr, n);
       vector<int> ans(n);
       for(int i = 0;i < n;i++)
       {
         ans[i] = i - pge[i];
       }
       return ans;
    }
};
