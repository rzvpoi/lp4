#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

// Function to check if a subgraph is a part of the main graph
bool isSubGraph(int mainGraph[MAX_SIZE][MAX_SIZE], int subGraph[MAX_SIZE][MAX_SIZE], int mainSize, int subSize) {
    bool isPart = true;

    // Check if all vertices of subgraph exist in the main graph
    for(int i = 0; i < subSize; i++) {
        for(int j = 0; j < subSize; j++) {
            if(subGraph[i][j] == 1 && mainGraph[i][j] == 0) {
                isPart = false;
                break;
            }
        }
        if(!isPart) break;
    }

    // Check if all edges of subgraph exist in the main graph
    for(int i = 0; i < subSize; i++) {
        for(int j = 0; j < subSize; j++) {
            if(subGraph[i][j] == 1 && mainGraph[i][j] == 1) {
                bool found = false;
                for(int k = 0; k < mainSize; k++) {
                    if(mainGraph[i][k] == 1 && mainGraph[k][j] == 1) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    isPart = false;
                    break;
                }
            }
        }
        if(!isPart) break;
    }

    return isPart;
}

int main() {
    int mainGraph[MAX_SIZE][MAX_SIZE];
    int subGraph[MAX_SIZE][MAX_SIZE];

    int mainSize, subSize;

    // Get the main graph
    cout << "Enter the number of vertices in the main graph: ";
    cin >> mainSize;

    cout << "Enter the adjacency matrix of the main graph:\n";
    for(int i = 0; i < mainSize; i++) {
        for(int j = 0; j < mainSize; j++) {
            cout << "Is there an edge between vertex " << i+1 << " and vertex " << j+1 << "? (1 for yes, 0 for no): ";
            cin >> mainGraph[i][j];
        }
    }

    // Get the subgraph
    cout << "Enter the number of vertices in the subgraph: ";
    cin >> subSize;

    cout << "Enter the adjacency matrix of the subgraph:\n";
    for(int i = 0; i < subSize; i++) {
        for(int j = 0; j < subSize; j++) {
            cout << "Is there an edge between vertex " << i+1 << " and vertex " << j+1 << "? (1 for yes, 0 for no): ";
            cin >> subGraph[i][j];
        }
    }

    if(isSubGraph(mainGraph, subGraph, mainSize, subSize)) {
        cout << "Subgraph is a part of the main graph.\n";
    } else {
        cout << "Subgraph is not a part of the main graph.\n";
    }

    return 0;
}
