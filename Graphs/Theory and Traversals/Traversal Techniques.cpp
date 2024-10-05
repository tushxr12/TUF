class Solution {
  private:
    void dfsHelper(int node, vector<int> adj[], int vis[], vector<int> &dfs)
    {
      vis[node] = 1;
      dfs.push_back(node);
      for(auto i : adj[node])
      {
        if(!vis[i])
        {
          dfsHelper(i, adj, vis, dfs);
        }
      }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        int vis[V] = {0};
        for(int i = 0;i < V;i++)
        {
          if(!vis[i])
          {
            dfsHelper(i, adj, vis, dfs);
          }
        }
        return dfs;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty())
        {
          int node = q.front();
          q.pop();
          bfs.push_back(node);

          for(auto i : adj[node])
          {
            if(!vis[i])
            {
              vis[i] = 1;
              q.push(i);
            }
          }
        }
        return bfs;
    }
};
