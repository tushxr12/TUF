//Recursion
class Solution {
private:
    int f(int i,int j, vector<vector<int>> &matrix)
    {
        if(i == 0 && j == 0 && matrix[i][j] != 1)
        {
            return 1;
        }
        if(i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;
        
        int up = f(i - 1,j,matrix);
        int left = f(i, j - 1, matrix);

        return (up + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        return f(n - 1,m - 1,matrix);
    }
};
