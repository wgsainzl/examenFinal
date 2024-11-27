//
// Created by maugv on 26/11/2024.
//

#include "UserManager.h"

// Agrega un nuevo usuario al sistema
void UserManager::addUser(const string& username) {
    if (userInterests.find(username) == userInterests.end()) {
        userInterests[username] = {};
        cout << "Usuario \"" << username << "\" agregado con éxito.\n";
    } else {
        cout << "El usuario \"" << username << "\" ya existe.\n";
    }
}

// Agrega un interés a un usuario
void UserManager::addInterest(const string& username, const string& interest) {
    auto it = userInterests.find(username);
    if (it != userInterests.end()) {
        it->second.insert(interest);
        cout << "Interés \"" << interest << "\" agregado al usuario \"" << username << "\".\n";
    } else {
        cout << "El usuario \"" << username << "\" no existe. No se pudo agregar el interés.\n";
    }
}

// Obtiene los intereses de un usuario
unordered_set<string> UserManager::getInterests(const string& username) const {
    auto it = userInterests.find(username);
    if (it != userInterests.end()) {
        return it->second;
    } else {
        cout << "El usuario \"" << username << "\" no existe.\n";
        return {};
    }
}
