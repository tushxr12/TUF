#define P pair<int,int>

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue <P, vector<P>, greater<P>> pq;
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if(dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
