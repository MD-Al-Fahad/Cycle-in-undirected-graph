
class Solution {
    private:
    bool detectcycle(int source,vector<int> adj[],int vis[])
    {
        vis[source] = 1;
        queue<pair<int,int>>qu;
        qu.push({source,-1});
        while(!qu.empty())
        {
            int node = qu.front().first;
            int parent = qu.front().second;
            qu.pop();
            for(auto v : adj[node])
            {
                if(!vis[v])
                {
                    vis[v] = 1;
                    qu.push({v,node});
                }
                else if(parent != v) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] ={0};
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
            {
                if(detectcycle(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
