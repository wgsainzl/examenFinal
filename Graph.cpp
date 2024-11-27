#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;

public:
    // Constructor
    Graph() {}

    // Método para agregar una conexión entre dos usuarios
    void addEdge(const std::string& user1, const std::string& user2);

    // Método para realizar BFS y encontrar todos los amigos de un usuario
    std::unordered_set<std::string> bfs(const std::string& startUser);
};

#endif // GRAPH_H
