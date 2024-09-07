class Solution
{
public:
    bool isPlacingPossible(vector<string> &board, int row, int col)
    {
        int r = row, c = col;

        // Check upper left diagonal
        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check left side
        while (c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check lower left diagonal
        while (r < board.size() && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        // If no queens are found, it's safe
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans)
    {
        if (col == board.size())
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < board.size(); row++)
        {
            if (isPlacingPossible(board, row, col))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        // your code goes here
        vector<vector<string>> ans;
        vector<string> board;
        string str = "";
        for (int i = 0; i < n; i++)
            str += ".";

        for (int j = 0; j < n; j++)
            board.push_back(str);

        solve(0, board, ans);
        return ans;
    }
};