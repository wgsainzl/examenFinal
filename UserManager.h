//
// Created by maugv on 26/11/2024.
//

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class UserManager {
private:
    unordered_map<string, unordered_set<string>> userInterests;

public:
    // Constructor y Destructor
    UserManager() = default;

    // Métodos públicos
    void addUser(const string& username);
    void addInterest(const string& username, const string& interest);
    unordered_set<string> getInterests(const string& username) const;
};

#endif // USERMANAGER_H

