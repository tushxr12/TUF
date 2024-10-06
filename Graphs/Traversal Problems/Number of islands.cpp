class Solution{
private:
    void bfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //Traverse neighbors
            for(int delRow = -1; delRow <= 1;delRow++)
            {
                for(int delCol = -1; delCol <= 1; delCol++)
                {
                    int nrow = row + delRow;
                    int ncol = col + delCol;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        vis[nrow][ncol] = 1;
                        bfs(nrow, ncol, vis, grid);
                    }
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
};
