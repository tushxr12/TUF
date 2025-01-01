class Solution
{
private:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        int nse ,pse , area, maxArea = 0;
        stack<int> st;

        for(int i = 0;i < n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                int ind = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();
                area = heights[ind] * (nse - pse - 1);
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        while(!st.empty())
        {
            int ind = st.top();
            st.pop();

            nse = n;
            pse = st.empty() ? -1 : st.top();
            area = heights[ind] * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> prefSum(n, vector<int>(m));

        for(int j = 0;j  <m;j++)
        {
            int sum = 0;
            for(int i = 0;i < n;i++)
            {
                sum += matrix[i][j];

                if(matrix[i][j] == 0)
                {
                    prefSum[i][j] = 0;
                    sum = 0;
                }
                prefSum[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0;i < n;i++)
        {
            int area = largestRectangleArea(prefSum[i]);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
