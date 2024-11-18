//Recursion
class Solution {
private:
    int f(int i,int j,vector<vector<int>> &triangle)
    {
        if(i == triangle.size() - 1)
        {
            return triangle[triangle.size() - 1][j];
        }

        int down = triangle[i][j] + f(i + 1,j,triangle);
        int rightDiagonal = triangle[i][j] + f(i + 1,j + 1,triangle);

        return min(down, rightDiagonal);
    }
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        return f(0,0,triangle);
    }
};
