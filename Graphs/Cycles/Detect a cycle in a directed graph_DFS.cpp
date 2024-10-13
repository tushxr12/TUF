class Solution{
private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node]  = 1;

        for(auto adjNode : adj[node])
        {
            if(!vis[adjNode])
            {
                if(dfs(adjNode, adj, vis, pathVis) == true)
                    return true;
            }
            else if(vis[adjNode] && pathVis[adjNode])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};

        for(int i = 0;i < V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
        return false;
    }
};
