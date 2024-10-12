class Solution
{
private:
    bool check(int node, int col, int color[], vector<int> adj[])
    {
        color[node] = col;
        for(auto adjNode : adj[node])
        {
            if(color[adjNode] == -1)
            {
                if(check(adjNode, !col, color, adj) == false)
                    return false;
            }
            else if(color[adjNode] == col)
                return false;
        }
        return true;
    }
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for(int i = 0;i < V;i++)
            color[i] = -1;
        
        for(int i = 0;i < V;i++)
        {
            if(color[i] == -1)
            {
                if(check(i, 0, color, adj) == false)    
                    return false;
            }
        }
        return true;
    }
};
