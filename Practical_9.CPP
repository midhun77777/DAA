#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    int selected[10] = {0};
    selected[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
