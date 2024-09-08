class Solution
{
public:
    void solve(int i, int j, string path, vector<vector<int>> &grid, int n, int m, vector<string> &ans)
    {
        if (i == n - 1 && j == m - 1)
        {
            ans.push_back(path);
            return;
        }

        if (grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        // Up
        if (i > 0)
            solve(i - 1, j, path + "U", grid, n, m, ans);

        // Right
        if (j + 1 < m)
            solve(i, j + 1, path + "R", grid, n, m, ans);

        // Down
        if (i + 1 < n)
            solve(i + 1, j, path + "D", grid, n, m, ans);

        // Left
        if (j > 0)
            solve(i, j - 1, path + "L", grid, n, m, ans);
        grid[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &grid)
    {
        // your code goes here
        vector<string> ans;
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
        {
            return ans;
        }
        solve(0, 0, "", grid, n, m, ans);
        return ans;
    }
};