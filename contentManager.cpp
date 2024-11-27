#include "contentManager.h"

//Agregar contenido a una categoría
void contentManager::addContent(const string& category, const string& content){
    contentMap[category].insert(content);//insertar el contenido en la categoría
}

//Contenidos de una categoría
vector<string> contentManager::getContentByCategory(const string& category) const {
    vector<string> result;//vector que contendrá los contenidos

    auto it = contentMap.find(category);//buscar la categoría

    //Si la categoría existe, guardar los contenidos
    if (it != contentMap.end()) {
        result.assign(it->second.begin(), it->second.end());
    }
    return result;
}

//Todas las categorias disponibles
vector<string> contentManager::getAllCategories() const {
    vector<string> categories;//vector que contendrá las categorías

    //Iterar sobre el mapa y guardar las categorías
    for (const auto& pair : contentMap) {
        categories.push_back(pair.first); 
    }
    return categories;
}