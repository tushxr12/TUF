class Solution
{
private:
    void dfs(int node, vector<int> adjList[], int vis[])
    {
        vis[node] = 1;
        for(auto i : adjList[node])
        {
            if(!vis[i])
            {
                dfs(i, adjList, vis);
            }
        }
    }
public:
    int numProvinces(vector<vector<int>> adj) {
       int v = adj.size();
       vector<int> adjList[v];

       for(int i = 0;i < v;i++)
       {
        for(int j = 0;j < v;j++)
        {
            if(adj[i][j] && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
       }

       int vis[v] = {0};
       int cnt = 0;

       for(int i = 0;i < v;i++)
       {
        if(!vis[i])
        {
            cnt++;
            dfs(i,adjList,vis);
        }
       }
       return cnt;
    }
};
