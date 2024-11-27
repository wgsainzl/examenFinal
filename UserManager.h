#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include "Graph.h"

using namespace std;

class UserManager {
protected:
    unordered_map<string, unordered_set<string>> userInterests; // Intereses de usuarios
    Graph friendships; // Grafo para gestionar relaciones de amistad

public:
    // Constructor y Destructor
    UserManager() = default;

    // Métodos públicos
    void addUser(const string& username);
    void addInterest(const string& username, const string& interest);
    void addFriendship(const string& user1, const string& user2);
    unordered_set<string> getInterests(const string& username) const;
    void recommendContent(const string& username);
    void removeUser(const string& username);
};

#endif // USERMANAGER_H
