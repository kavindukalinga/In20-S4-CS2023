#include <iostream>
#include <vector>

using namespace std;

vector<int> dijkstra(vector<vector<int>> graph, int source) {
    int n = graph.size();
    vector<int> distances(n, -1);
    vector<bool> visited(n, false);

    distances[source] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int minDistance = INT_MAX;
        int u = -1;

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && distances[i] != -1 && distances[i] < minDistance) {
                minDistance = distances[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != 0) {
                int weight = graph[u][v];

                if (distances[u] + weight < distances[v] || distances[v] == -1)
                    distances[v] = distances[u] + weight;
            }
        }
    }

    return distances;
}

int main() {
    // Weighted adjacency matrix
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 5, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();

    for (int source = 0; source < numCities; ++source) {
        vector<int> shortestTimes = dijkstra(graph, source);

        cout << "Shortest times from City " << source << " to" << endl;
        for (int i = 0; i < numCities; ++i) {
            if (i != source) {
                cout << "city " << i << " = ";
                if (shortestTimes[i] != -1)
                    cout << shortestTimes[i];
                else
                    cout << "Not reachable";
                cout << endl;
            }
        }
        cout << endl << endl;
    }

    return 0;
}
