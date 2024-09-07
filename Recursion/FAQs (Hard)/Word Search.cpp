class Solution
{
public:
    bool solve(int ind, int i, int j, int n, int m, vector<vector<char>> &board, string word)
    {
        if (ind == word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '.' || board[i][j] != word[ind])
            return false;

        bool ans = false;
        char visitedChar = board[i][j];
        // visited
        board[i][j] = '.';

        // top
        ans = ans || solve(ind + 1, i - 1, j, n, m, board, word);

        // down
        ans = ans || solve(ind + 1, i + 1, j, n, m, board, word);

        // right
        ans = ans || solve(ind + 1, i, j + 1, n, m, board, word);

        // left
        ans = ans || solve(ind + 1, i, j - 1, n, m, board, word);

        board[i][j] = visitedChar;
        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        // your code goes here
        int row = board.size();
        int cols = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Check for all starting points and then explore all possibilities
                if (word[0] == board[i][j])
                {
                    if (solve(0, i, j, row, cols, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};