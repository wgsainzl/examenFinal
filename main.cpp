#include <iostream>

using namespace std;

void mostrarMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Crear amistad" << endl;
    cout << "2. Agregar contenido" << endl;
    cout << "3. Agregar interés a un usuario" << endl;
    cout << "4. Ver recomendaciones" << endl;
    cout << "5. Agregar usuario" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Has seleccionado: Crear amistad" << endl;
            break;
        case 2:
            cout << "Has seleccionado: Agregar contenido" << endl;
            break;
        case 3:
            cout << "Has seleccionado: Agregar interés a un usuario" << endl;
            break;
        case 4:
            cout << "Has seleccionado: Ver recomendaciones" << endl;
            break;
        case 5:
            cout << "Has seleccionado: Agregar usuario" << endl;
            break;
        case 6:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
        cout << endl;
    } while (opcion != 6);

    return 0;
}
