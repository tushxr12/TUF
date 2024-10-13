class Solution{
private:
    void dfs(int node, stack<int> &st, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for(auto adjNode : adj[node])
        {
            if(!vis[adjNode])
                dfs(adjNode, st, adj, vis);
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int vis[V] = {0};
        stack<int> st;
        for(int i = 0;i < V;i++)
        {
            if(!vis[i])
            {
                dfs(i, st, adj, vis);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
