class Solution
{
private:
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto adjNode : adj[node])
            {
                if(color[adjNode] == -1)
                {
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode] == color[node])
                {
                    return false;
                }
            }
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
                if(check(i, V, adj, color) == false)
                {
                    return false;
                }
        }
        return true;
    }
};
