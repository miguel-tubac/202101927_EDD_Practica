#include <iostream>
using namespace std;

void cargarAviones() {
    cout << "Cargando aviones..." << endl;
    // Aquí iría el código para cargar aviones
}

void cargarPasajeros() {
    cout << "Cargando pasajeros..." << endl;
    // Aquí iría el código para cargar pasajeros
}

void cargarMovimientos() {
    cout << "Cargando movimientos..." << endl;
    // Aquí iría el código para cargar movimientos
}

int main() {
    int opcion;

    do {
        cout << "------------------------MENU-----------------------" << endl;
        cout << "1. Carga de aviones" << endl;
        cout << "2. Carga de pasajeros" << endl;
        cout << "3. Carga de movimientos" << endl;
        cout << "4. Consultar pasajeros" << endl;
        cout << "5. Visualizar reporte" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cargarAviones();
                break;
            case 2:
                cargarPasajeros();
                break;
            case 3:
                cargarMovimientos();
                break;
            case 4:
                cargarMovimientos();
                break;
            case 5:
                cargarMovimientos();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }

        cout << endl;
    } while(opcion != 6);

    return 0;
}
