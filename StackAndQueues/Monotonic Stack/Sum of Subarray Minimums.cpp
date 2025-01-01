class Solution {
private:
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1;i >= 0;i--)
        {
            int currElement = arr[i];

            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0;i < n;i++)
        {
            int currElement = arr[i];

            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
public:
    int sumSubarrayMins(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        int n = arr.size();
        int mod = 1e9 + 7;

        int sum = 0;

        for(int i = 0;i < n;i++)
        {
            int left = i - pse[i];
            int right = nse[i] - i;
            long long count = left*right*1LL;
            int val = (count*arr[i]*1LL)%mod;
            sum = (sum + val)%mod;
        }
        return sum;
    }
};
