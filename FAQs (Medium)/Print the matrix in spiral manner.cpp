class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        /*
            [1,2,3]
            [4,5,6]
            [7,8,9]
        */
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int top = 0, right = m - 1, bottom = n - 1, left = 0;

        while (top <= bottom && left <= right)
        {
            // Store Top left to Right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Store top to bottom
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom)
            {
                // Store Bottom Right to Left
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                // Store Bottom to Top
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};