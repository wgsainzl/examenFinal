#include "Graph.h"

// Agrega una conexión entre dos usuarios
void Graph::addEdge(const std::string& user1, const std::string& user2) {
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1);
}

// Realiza BFS para encontrar todos los amigos (directos e indirectos) de un usuario
std::unordered_set<std::string> Graph::bfs(const std::string& startUser) {
    std::unordered_set<std::string> visited; // Conjunto para evitar visitar nodos repetidos
    std::queue<std::string> q; // Cola para BFS
    std::unordered_set<std::string> result; // Resultado con los amigos encontrados

    if (adjList.find(startUser) == adjList.end()) {
        return result; // Si el usuario no existe, devolver vacío
    }

    q.push(startUser);
    visited.insert(startUser);

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        // Agregar el usuario actual a los resultados
        result.insert(current);

        // Explorar los vecinos
        for (const auto& neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    // Eliminar el usuario inicial si no se quiere incluir en el resultado final
    result.erase(startUser);

    return result;
}
