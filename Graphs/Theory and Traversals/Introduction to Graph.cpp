#include<bits/stdc++.h>

using namespace std;

int main()
{
    //###################################//
    //Taking graph input in adjacency matrix
    int n,m;
    cin>>n>>m;
    int adj[n + 1][m + 1];

    //Initializing matrix to 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            adj[i][j] = 0;
        }
    }

    //Taking edges input
    for(int i = 0;i < m;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //Printing graph
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= m;j++)
            cout<<adj[i][j]<<" ";
        cout<<"\n";
    }
    //###################################//

    //###################################//
    //Taking graph input in adjacency list
    int n,m;
    cin>>n>>m;
    vector<int> adj[n + 1];
    
    //Taking input of edges
    for(int i = 0;i < m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //Printing graph
    for(int i = 0;i <= n;i++)
    {
        if(i == 0)
            continue;
        cout<<i<<" : ";
        for(int j = 0;j < adj[i].size();j++)
            if(j == adj[i].size() - 1)
                cout<<adj[i][j];
            else
                cout<<adj[i][j]<<"->";
        cout<<"\n";
    }
    //###################################//
    return 0;
}
