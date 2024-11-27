#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class contentManager{
    private:
        unordered_map<string, unordered_set<string>> contentMap;
    
    public:
        //Agregar contenido a una categoría
        void addContent(const string& category, const string& content);

        //Contenidos de una categoría
        vector<string> getContentByCategory(const string& category)const;

        //Todas las categorias disponibles
        vector<string> getAllCategories()const;
};

#endif // CONTENTMANAGER_H