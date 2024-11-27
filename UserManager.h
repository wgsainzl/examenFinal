//
// Created by maugv on 26/11/2024.
//

#ifndef EXAMENFINALLL_USERMANAGER_H
#define EXAMENFINALLL_USERMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class UserManager {
private:
    // Crear un grafo de usuarios que contenga los intereses de cada usuario
    unordered_map<string, unordered_set<string>> userInterests;

public:
    // Constructor
    UserManager() = default;

    // Métodos públicos
    void addUser(const string& username);
    void addInterest(const string& username, const string& interest);
    unordered_set<string> getInterests(const string& username) const;
};


#endif //EXAMENFINALLL_USERMANAGER_H
