class Solution
{
public:
    bool rulesAreMet(vector<vector<char>> &board, int row, int col, char digit)
    {

        // Check in row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == digit || board[i][col] == digit)
                return false;
        }
        // Check in subgrid
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
                if (board[i][j] == digit)
                    return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = 9;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char digit = '1'; digit <= '9'; digit++)
                    {
                        if (rulesAreMet(board, i, j, digit))
                        {
                            board[i][j] = digit;
                            if (solve(board))
                            {
                                return true;
                            }
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};