// Brute
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        /*
            [1,1,2]  [5, 5, 1]
            [5,3,1]  [3, 3, 1]
            [5,3,5]  [5, 1, 2]
        */
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};

// Optimal
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        /*
            [1,1,2]  [5, 5, 1]
            [5,3,1]  [3, 3, 1]
            [5,3,5]  [5, 1, 2]
        */
        // Find transpose and then reverse each row in the matrix
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};