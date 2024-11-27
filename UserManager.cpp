#include "UserManager.h"

void UserManager::addUser(const string& username) {
    if (userInterests.find(username) == userInterests.end()) {
        userInterests[username] = {};
        cout << "Usuario \"" << username << "\" agregado con éxito.\n";
    } else {
        cout << "El usuario \"" << username << "\" ya existe.\n";
    }
}

void UserManager::addInterest(const string& username, const string& interest) {
    auto it = userInterests.find(username);
    if (it != userInterests.end()) {
        it->second.insert(interest);
        cout << "Interés \"" << interest << "\" agregado al usuario \"" << username << "\".\n";
    } else {
        cout << "El usuario \"" << username << "\" no existe. No se pudo agregar el interés.\n";
    }
}

unordered_set<string> UserManager::getInterests(const string& username) const {
    auto it = userInterests.find(username);
    if (it != userInterests.end()) {
        return it->second;
    } else {
        cout << "El usuario \"" << username << "\" no existe.\n";
        return {};
    }
}

void UserManager::addFriendship(const string& user1, const string& user2) {
    if (userInterests.find(user1) != userInterests.end() && userInterests.find(user2) != userInterests.end()) {
        friendships.addEdge(user1, user2); // Usar el grafo para registrar la amistad
        cout << "Amistad creada entre \"" << user1 << "\" y \"" << user2 << "\".\n";
    } else {
        cout << "Uno o ambos usuarios no existen. No se puede crear la amistad.\n";
    }
}

void UserManager::recommendContent(const string& username) {
    // Verificar si el usuario existe
    if (userInterests.find(username) == userInterests.end()) {
        cout << "El usuario \"" << username << "\" no existe. No se puede generar recomendaciones.\n";
        return;
    }

    // Usar BFS para obtener amigos directos e indirectos
    unordered_set<string> friends = friendships.bfs(username);
    if (friends.empty()) {
        cout << "El usuario \"" << username << "\" no tiene amigos registrados para generar recomendaciones.\n";
        return;
    }

    unordered_map<string, int> interestFrequency; // Contar los intereses sugeridos

    // Revisar intereses de los amigos
    for (const string& friendName : friends) {
        const auto& friendInterests = userInterests[friendName];
        for (const string& interest : friendInterests) {
            if (userInterests[username].find(interest) == userInterests[username].end()) {
                // Solo contar intereses que no tenga el usuario
                interestFrequency[interest]++;
            }
        }
    }

    // Generar las recomendaciones
    cout << "Recomendaciones de contenido basadas en los amigos de \"" << username << "\":\n";
    for (const auto& [interest, frequency] : interestFrequency) {
        cout << "- " << interest << " (popularidad entre amigos: " << frequency << ")\n";
    }
}
