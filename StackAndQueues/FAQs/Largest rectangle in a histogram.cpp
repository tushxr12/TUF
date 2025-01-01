class Solution
{
private:
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0;i--)
        {
            int currElement= arr[i];
 
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n;i++)
        {
            int currElement= arr[i];
 
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        // cout<<"NSE : ";
        // for(auto i : nse)
        //     cout<<i<<" ";
        // cout<<"\nPSE : ";
        // for(auto i : pse)
        //     cout<<i<<" ";

        int largestArea = 0;
        
        int n = heights.size();
        for(int i = 0;i < n;i++)
        {
            int area = heights[i]*(nse[i] - pse[i] - 1);
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};

//Optimal
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int largestArea = 0;
        int area;
        int nse , pse;

        for(int i = 0;i < n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                int ind = st.top();
                st.pop();

                pse = st.empty() ? -1 : st.top();

                nse = i;

                area = heights[ind] * (nse - pse - 1);
                largestArea = max(largestArea, area);
            }
            st.push(i);
        }

        while(!st.empty())
        {
            nse = n;
            int ind = st.top();
            st.pop();

            pse = st.empty() ? - 1 : st.top();
            area = heights[ind] * (nse - pse - 1);
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};
