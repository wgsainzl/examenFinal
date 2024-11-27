#include "Graph.h"

// Agrega una conexión entre dos usuarios
void Graph::addEdge(const string& user1, const string& user2) {
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1);
}

// Realiza BFS para encontrar todos los amigos (directos e indirectos) de un usuario
unordered_set<string> Graph::bfs(const string& startUser) {
    unordered_set<string> visited;
    queue<string> q;
    unordered_set<string> result;

    if (adjList.find(startUser) == adjList.end()) {
        return result;
    }

    q.push(startUser);
    visited.insert(startUser);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        result.insert(current);

        for (const auto& neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    result.erase(startUser);

    return result;
}

// Elimina una conexión entre dos usuarios
void Graph::removeEdge(const string& user1, const string& user2) {
    // Si el usuario 1 existe en el grafo, eliminamos a user2 de sus vecinos
    if (adjList.find(user1) != adjList.end()) {
        auto& neighbors1 = adjList[user1];
        neighbors1.erase(remove(neighbors1.begin(), neighbors1.end(), user2), neighbors1.end());
    }

    // Si el usuario 2 existe en el grafo, eliminamos a user1 de sus vecinos
    if (adjList.find(user2) != adjList.end()) {
        auto& neighbors2 = adjList[user2];
        neighbors2.erase(remove(neighbors2.begin(), neighbors2.end(), user1), neighbors2.end());
    }
}
