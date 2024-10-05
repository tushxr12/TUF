class Solution {
  private:
    void bfs(int node, vector<int> adj[], bool visited[])
    {
      visited[node] = true;
      queue<int> q;
      q.push(node);

      while(!q.empty())
      {
        int i = q.front();
        q.pop();

        for(auto adjNodes : adj[i])
        {
          if(!visited[adjNodes])
          {
            visited[adjNodes] = true;
            q.push(adjNodes);
          }
        }
      }
    }
  public:
    int findNumberOfComponent(int E, int V, vector<vector<int>> &edges) {
        vector<int> adj[V];

        for(int i = 0;i < E;i++)
        {
          adj[edges[i][0]].push_back(edges[i][1]);
          adj[edges[i][1]].push_back(edges[i][0]);
        }

        bool visited[V] = {0};

        int ans = 0;

        for(int i = 0;i < V;i++)
        {
          if(!visited[i])
          {
            ans++;
            bfs(i, adj, visited);
          }
        }
        return ans;
    }
};
