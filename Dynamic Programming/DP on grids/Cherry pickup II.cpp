//Recursion
class Solution {
private:
    int f(int i,int j1,int j2,int r,int c, vector<vector<int>> &matrix)
    {
        if(j1 < 0 || j2 <= 0|| j1 >= c || j2 >= c)
        {
            return -1e8;
        }

        if(i == r -1)
        {
            if(j1 == j2)    
                return matrix[i][j1];
            else
                return matrix[i][j1] + matrix[i][j2];
        }

        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= +1;dj1++)
        {
            for(int dj2 = -1;dj2 <= +1;dj2++)
            {
                int val = 0;
                if(j1 == j2)
                    val = matrix[i][j1];
                else
                    val = matrix[i][j1] + matrix[i][j2];
                val += f(i + 1,j1+dj1,j2+dj2,r,c,matrix);
                maxi = max(maxi, val);
            }
        }
        return maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        return f(0,0,c - 1,r,c,matrix);
    }
};
