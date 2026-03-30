// Time Complexity: O(K × E)
// K = maximum number of stops
// E = number of flights (edges)
// We process all edges for up to K levels

// Space Complexity: O(N + E)
// N = number of cities (nodes)
// E = adjacency list storage
// Additional space used by queue and cost array

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int k) {
            
            vector<vector<pair<int,int>>> graph(n);
            for(int i = 0; i < flights.size(); i++) {
                int from = flights[i][0];
                int to = flights[i][1];
                int cost = flights[i][2];
                graph[from].push_back({to, cost});
            }
    
            vector<int> best(n, INT_MAX);
            best[s] = 0;
    
            queue<vector<int>> q;
            q.push({s, 0, 0});
    
            while(!q.empty()) {
                vector<int> cur = q.front();
                q.pop();
    
                int node = cur[0];
                int costSoFar = cur[1];
                int steps = cur[2];
    
                if(steps > k) continue;
    
                for(int i = 0; i < graph[node].size(); i++) {
                    int nextNode = graph[node][i].first;
                    int edgeCost = graph[node][i].second;
    
                    int newCost = costSoFar + edgeCost;
    
                    if(newCost < best[nextNode]) {
                        best[nextNode] = newCost;
    
                        vector<int> temp;
                        temp.push_back(nextNode);
                        temp.push_back(newCost);
                        temp.push_back(steps + 1);
    
                        q.push(temp);
                    }
                }
            }
    
            return best[d] == INT_MAX ? -1 : best[d];
        }
    };