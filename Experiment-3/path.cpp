#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool findPath(int curr, int count, vector<vector<int>>& adj, vector<bool>& vis, int n) {
        if (count == n) return true;

        for (auto neighbor : adj[curr]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true; // Mark
                if (findPath(neighbor, count + 1, adj, vis, n)) 
                    return true;
                vis[neighbor] = false; // Backtrack
            }
        }
        return false;
    }

    bool check(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0] - 1; 
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            visited[i] = true;
            if (findPath(i, 1, adj, visited, n)) {
                return true;
            }
        }

        return false;
    }
};