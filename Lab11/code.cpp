#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<vector<int>> Graph;

vector<int> primMST(const Graph& graph, int startNode) {
    int allNodes = graph.size();
    vector<bool> visited(allNodes, false);
    vector<int> parent(allNodes, -1);
    vector<int> dist(allNodes, numeric_limits<int>::max());

    dist[startNode] = 0;

    for (int i = 0; i < allNodes - 1; ++i) {
        int u = -1;
        int distMin = numeric_limits<int>::max();

        for (int j = 0; j < allNodes; ++j) {
            if (!visited[j] && dist[j] < distMin) {
                distMin = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < allNodes; ++v) {
            if (!visited[v] && graph[u][v] != 0 && graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }

    return parent;
}

int main() {
        int allNodes=6;
        Graph graph(allNodes, vector<int>(allNodes, 0));
        graph[0][1] = 3; graph[1][0] = 3;
        graph[1][3] = 1; graph[3][1] = 1;
        graph[2][1] = 2; graph[1][2] = 2;
        graph[2][3] = 3; graph[3][2] = 3;
        graph[3][4] = 5; graph[4][3] = 5;
        graph[4][5] = 4; graph[5][4] = 4;
        graph[0][5] = 1; graph[5][0] = 1;
        graph[2][5] = 5; graph[5][2] = 5;
        graph[4][1] = 10; graph[1][4] = 10;

    vector<int> parent = primMST(graph, 0);

    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < allNodes; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }

    return 0;
}
