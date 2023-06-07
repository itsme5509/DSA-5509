#include <iostream>
#include <vector>
#include <queue>
#include <map>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    std::map<int, std::vector<int>> adjList;

public:
    void addEdge(int source, int destination) {
        adjList[source].push_back(destination);
        adjList[destination].push_back(source);
    }

    void printAdjList() {
        std::cout << "Adjacency List:" << std::endl;
        for (const auto& entry : adjList) {
            std::cout << entry.first << " -> ";
            for (const auto& neighbor : entry.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(int startNode) {
        std::vector<bool> visited(adjList.size(), false);
        std::queue<int> queue;
        visited[startNode] = true;
        queue.push(startNode);
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();
            std::cout << currentNode << " ";
            for (const auto& neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph graph;

    int choice;
    do {
        std::cout << "\nGraph Operations Menu:" << std::endl;
        std::cout << "1. Add an edge" << std::endl;
        std::cout << "2. Print adjacency list" << std::endl;
        std::cout << "3. Perform BFS" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int source, destination;
                std::cout << "Enter the source node: ";
                std::cin >> source;
                std::cout << "Enter the destination node: ";
                std::cin >> destination;
                graph.addEdge(source, destination);
                break;
            }
            case 2:
                graph.printAdjList();
                break;
            case 3: {
                int startNode;
                std::cout << "Enter the start node for BFS: ";
                std::cin >> startNode;
                std::cout << "BFS: ";
                graph.BFS(startNode);
                std::cout << std::endl;
                break;
            }
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }

    } while (choice != 4);

    return 0;
}

