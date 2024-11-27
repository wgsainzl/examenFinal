#include <iostream>
#include "Graph.h"
#include "contentManager.h"
#include "UserManager.h"

using namespace std;

void mostrarMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Crear amistad" << endl;
    cout << "2. Agregar contenido" << endl;
    cout << "3. Agregar interés a un usuario" << endl;
    cout << "4. Ver recomendaciones" << endl;
    cout << "5. Agregar usuario" << endl;
    cout << "6. Eliminar usuario" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Graph graph;
    contentManager contentMgr;
    UserManager userMgr;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string user1, user2;
            cout << "Ingrese el primer usuario: ";
            cin >> user1;
            cout << "Ingrese el segundo usuario: ";
            cin >> user2;
            userMgr.addFriendship(user1, user2);
            break;
        }
        case 2: {
            string category, content;
            cout << "Ingrese la categoría: ";
            cin >> category;
            cout << "Ingrese el contenido: ";
            cin >> content;
            contentMgr.addContent(category, content);
            cout << "Contenido agregado a la categoría " << category << endl;
            break;
        }
        case 3: {
            string username, interest;
            cout << "Ingrese el nombre del usuario: ";
            cin >> username;
            cout << "Ingrese el interés: ";
            cin >> interest;
            userMgr.addInterest(username, interest);
            break;
        }
        case 4: {
            string username;
            cout << "Ingrese el nombre del usuario: ";
            cin >> username;
            userMgr.recommendContent(username);
            break;
        }
        case 5: {
            string username;
            cout << "Ingrese el nombre del usuario: ";
            cin >> username;
            userMgr.addUser(username);
            break;
        }
        case 6: {
            string username;
            cout << "Ingrese el nombre del usuario: ";
            cin >> username;
            userMgr.removeUser(username);
            break;
        }
        case 7:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 7 && !cin.fail());
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada no válida. Saliendo..." << endl;
    }

    return 0;
}
