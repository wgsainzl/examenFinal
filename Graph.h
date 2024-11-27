#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <algorithm> // Para std::remove

using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> adjList;

public:
    // Constructor
    Graph() {}

    // Método para agregar una conexión entre dos usuarios
    void addEdge(const string& user1, const string& user2);

    // Método para realizar BFS y encontrar todos los amigos de un usuario
    unordered_set<string> bfs(const string& startUser);

    // Método para eliminar una conexión entre dos usuarios
    void removeEdge(const string& user1, const string& user2);
};

#endif // GRAPH_H
