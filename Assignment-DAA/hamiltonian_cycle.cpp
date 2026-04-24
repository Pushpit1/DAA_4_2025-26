// Hamiltonian Cycle Time Complexity

// Worst Case Time Complexity: O(V!)
// Explanation:
// Try all possible permutations of vertices
// Backtracking explores all possible paths

// Space Complexity: O(V)
// (for path array + recursion stack)

#include <bits/stdc++.h>
using namespace std;

#define V 5

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool solve(int pos, vector<vector<int>>& graph, vector<int>& path) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (solve(pos + 1, graph, path))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonianCycle(vector<vector<int>>& graph) {
    vector<int> path(V, -1);

    path[0] = 0;

    if (!solve(1, graph, path)) {
        cout << "No Hamiltonian Cycle\n";
        return;
    }

    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    hamiltonianCycle(graph);

    return 0;
}