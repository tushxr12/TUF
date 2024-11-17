//Recursion
class Solution {
private:
    int f(int i,int j)
    {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        int up = f(i - 1,j);
        int left = f(i, j -1);
        return (up + left);
    }
public:
    int uniquePaths(int n, int m) {
        return f(n - 1,m - 1);
    }
};
