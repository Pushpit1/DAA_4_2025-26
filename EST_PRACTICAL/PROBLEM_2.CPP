#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            for (auto &nei : adj[node]) {
                int adjNode = nei.first;
                int weight = nei.second;

                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};