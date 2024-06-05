#include <iostream>
#include <fstream>
using namespace std;
#include "importaciones/tinyfiledialogs.h" 
#include "importaciones/json.hpp"

//Importaciones de las clases
#include "clasesPropias/Aviones.h"
#include "clasesPropias/ListaCircularDoble.h"

// Para simplificar, usaremos un alias para el tipo de datos JSON
using json = nlohmann::json;

// Aca se crean las dos listas doblemente enlazadas:
ListaCircularDoble listaAvionesDisponibles;
ListaCircularDoble listaAvionesMantenimiento;

void cargarAviones() {
    cout << "Cargando aviones..." << endl;
    const char * filterPatterns[] = { "*.json" };
    const char * filePath = tinyfd_openFileDialog(
        "Seleccione un archivo JSON",  // Título de la ventana
        "",                            // Ruta inicial (vacío significa directorio actual)
        1,                             // Número de filtros
        filterPatterns,                // Filtros de archivos
        NULL,                          // Descripción del filtro
        0                              // Permitir seleccionar múltiples archivos (0: no, 1: sí)
    );

    if (filePath) {
        std::cout << "Archivo seleccionado: " << filePath << std::endl;
        // Aquí iría el código para manejar el archivo seleccionado

        // Leer el archivo JSON
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return;
        }

        // Parsear el archivo JSON
        json aviones;
        file >> aviones;


        // Procesar los datos del JSON
        for (const auto& avion : aviones) {
            if(avion["estado"] == "Disponible"){
                cout<< "Ingresando en aviones Disponibles"<< endl;
                Aviones* avion1 = new Aviones(avion["vuelo"], avion["numero_de_registro"], avion["modelo"], avion["fabricante"], avion["ano_fabricacion"], avion["capacidad"], avion["peso_max_despege"], avion["aerolinea"], avion["estado"]);
                listaAvionesDisponibles.insert(avion1);
            }
            else if(avion["estado"] == "Mantenimiento"){
                cout<< "Ingresando en aviones en Mantenimiento"<< endl;
                Aviones* avion2 = new Aviones(avion["vuelo"], avion["numero_de_registro"], avion["modelo"], avion["fabricante"], avion["ano_fabricacion"], avion["capacidad"], avion["peso_max_despege"], avion["aerolinea"], avion["estado"]);
                listaAvionesMantenimiento.insert(avion2);
            }
            /*
            std::cout << "Vuelo: " << avion["vuelo"] << std::endl;
            std::cout << "Número de registro: " << avion["numero_de_registro"] << std::endl;
            std::cout << "Modelo: " << avion["modelo"] << std::endl;
            std::cout << "Fabricante: " << avion["fabricante"] << std::endl;
            std::cout << "Año de fabricación: " << avion["ano_fabricacion"] << std::endl;
            std::cout << "Capacidad: " << avion["capacidad"] << std::endl;
            std::cout << "Peso máximo de despegue: " << avion["peso_max_despege"] << std::endl;
            std::cout << "Aerolínea: " << avion["aerolinea"] << std::endl;
            std::cout << "Estado: " << avion["estado"] << std::endl;
            std::cout << "---------------------------" << std::endl;
            */
        }
        // Mostrar todos los aviones en la lista
        //listaAvionesDisponibles.display();
        listaAvionesMantenimiento.display();
    } else {
        std::cout << "No se seleccionó ningún archivo." << std::endl;
    }
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
