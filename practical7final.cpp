#include <iostream>
#include <vector>

using namespace std;

class Graph 
{
private:
    vector<vector<int>> adjMatrix;

public:
    Graph(int numNodes) 
    {
        adjMatrix.resize(numNodes, vector<int>(numNodes, 0));
    }

    void addEdge(int source, int destination) 
    {
        adjMatrix[source][destination] = 1;
        adjMatrix[destination][source] = 1;
    }

    void printAdjMatrix() 
    {
        cout << "Adjacency Matrix:" << endl;
        for (const auto& row : adjMatrix) {
            for (const auto& value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }

    void DFS(int startNode) 
    {
        vector<bool> visited(adjMatrix.size(), false);
        DFSUtil(startNode, visited);
    }

    void DFSUtil(int currentNode, vector<bool>& visited) {
        visited[currentNode] = true;
        cout << currentNode << " ";
        for (int neighbor = 0; neighbor < adjMatrix.size(); ++neighbor) {
            if (adjMatrix[currentNode][neighbor] == 1 && !visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() 
{
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Graph graph(numNodes);

    int choice;
    do {
        cout << "\nGraph Operations Menu:" << endl;
        cout << "1. Add an edge" << endl;
        cout << "2. Print adjacency matrix" << endl;
        cout << "3. Perform DFS" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int source, destination;
                cout << "Enter the source node: ";
                cin >> source;
                cout << "Enter the destination node: ";
                cin >> destination;
                graph.addEdge(source, destination);
                break;
            }
            case 2:
                graph.printAdjMatrix();
                break;
            case 3: {
                int startNode;
                cout << "Enter the start node for DFS: ";
                cin >> startNode;
                cout << "DFS: ";
                graph.DFS(startNode);
                cout << endl;
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
