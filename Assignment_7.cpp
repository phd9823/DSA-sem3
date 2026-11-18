#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int adj[20][20];
    bool visited[20];

public:
    void createGraph() {
        cout << "Enter number of intersections: ";
        cin >> vertices;

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0;
            }
            visited[i] = false;
        }

        int edges;
        cout << "Enter number of roads: ";
        cin >> edges;

        for (int k = 0; k < edges; k++) {
            int u, v;
            cout << "Enter road connection (source destination): ";
            cin >> u >> v;
            if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
                adj[u][v] = 1;
                adj[v][u] = 1;
            } else {
                cout << "Invalid vertex index! Try again.\n";
                k--;
            }
        }
    }

    void displayGraph() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        visited[start] = true;
        cout << start << " ";

        for (int i = 0; i < vertices; i++) {
            if (adj[start][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }

    void resetVisited() {
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }

    int getVertices() {
        return vertices;
    }
};

int main() {
    Graph cityRoad;
    int choice;

    do {
        cout << "\n=================================\n";
        cout << " Road Network Exploration using DFS\n";
        cout << "=================================\n";
        cout << "1. Create Road Network\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Perform DFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cityRoad.createGraph();
                break;
            case 2:
                cityRoad.displayGraph();
                break;
            case 3: {
                int start;
                cout << "Enter starting intersection: ";
                cin >> start;
                if (start >= 0 && start < cityRoad.getVertices()) {
                    cityRoad.resetVisited();
                    cout << "DFS Traversal Order: ";
                    cityRoad.DFS(start);
                    cout << endl;
                } else {
                    cout << "Invalid starting intersection!\n";
                }
                break;
            }
            case 4:
                cout << "Program Terminated Successfully.\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}