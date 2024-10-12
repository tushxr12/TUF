class Solution{
private:
    bool detect(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for(auto adjNode : adj[node])
        {
            if(!vis[adjNode])
            {
                if(detect(adjNode, node, vis, adj) == true)
                    return true;
            }
            else if(adjNode != parent)
                return true;
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0;i < V;i++)
        {
            if(!vis[i])
            {
                if(detect(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};
