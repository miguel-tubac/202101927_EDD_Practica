#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "importaciones/tinyfiledialogs.h" 
#include "importaciones/json.hpp"

//Importaciones de las clases
#include "clasesPropias/Aviones.h"
#include "clasesPropias/ListaCircularDoble.h"
#include "clasesPropias/Pasajeros.h"
#include "clasesPropias/Cola.h"
#include "clasesPropias/Pila.h"
#include "clasesPropias/ListaEnlazadaDoble.h"
#include "clasesPropias/NodoAviones.h"

// Para simplificar, usaremos un alias para el tipo de datos JSON
using json = nlohmann::json;

// Aca se crean las dos listas doblemente enlazadas:
ListaCircularDoble listaAvionesDisponibles;
ListaCircularDoble listaAvionesMantenimiento;

// Aca se cra la cola para los pasajeros:
Cola colaPasajeros;

// Aca se almacenaran la Pila de Equipaje:
Pila pilaEquipajes;

// Aca se almacenaran los pasajeros que salgan de la cola
ListaEnlazadaDoble ListaEnlazadaDoblePasajeros;

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
        //std::cout << "Archivo seleccionado: " << filePath << std::endl;
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

        listaAvionesDisponibles.vaciar();
        listaAvionesMantenimiento.vaciar();
        // Procesar los datos del JSON
        for (const auto& avion : aviones) {
            if(avion["estado"] == "Disponible"){
                //cout<< "Ingresando en aviones Disponibles"<< endl;
                Aviones* avion1 = new Aviones(avion["vuelo"], avion["numero_de_registro"], avion["modelo"], avion["fabricante"], avion["ano_fabricacion"], avion["capacidad"], avion["peso_max_despegue"], avion["aerolinea"], avion["estado"]);
                listaAvionesDisponibles.insert(avion1);
            }
            else if(avion["estado"] == "Mantenimiento"){
                //cout<< "Ingresando en aviones en Mantenimiento"<< endl;
                Aviones* avion2 = new Aviones(avion["vuelo"], avion["numero_de_registro"], avion["modelo"], avion["fabricante"], avion["ano_fabricacion"], avion["capacidad"], avion["peso_max_despegue"], avion["aerolinea"], avion["estado"]);
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
        //listaAvionesMantenimiento.display();
        cout << "Se Cargaron los Aviones correctamente. Press Enter..." << endl;
        // Para detenerse hasta que se presione Enter
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar cualquier entrada previa
        cin.get();  // Esperar hasta que se presione Enter
    } else {
        std::cout << "No se selecciono ningun archivo." << std::endl;
    }
}

void cargarPasajeros() {
    cout << "Cargando Pasajeros..." << endl;
    // Aquí iría el código para cargar pasajeros

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
        //std::cout << "Archivo seleccionado: " << filePath << std::endl;
        // Aquí iría el código para manejar el archivo seleccionado

        // Leer el archivo JSON
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return;
        }

        // Parsear el archivo JSON
        json pasajeros;
        file >> pasajeros;

        colaPasajeros.vaciar();
        // Procesar los datos del JSON
        for (const auto& pasajero : pasajeros) {
            Pasajeros* nuevoPasajero = new Pasajeros(pasajero["nombre"], pasajero["nacionalidad"], pasajero["numero_de_pasaporte"], pasajero["vuelo"], pasajero["asiento"], pasajero["destino"], pasajero["origen"], pasajero["equipaje_facturado"]);
            colaPasajeros.encolar(nuevoPasajero);
            /*
            std::cout << "Nombre: " << pasajero["nombre"] << std::endl;
            std::cout << "Nacionalidad: " << pasajero["nacionalidad"] << std::endl;
            std::cout << "Numero_De_Pasaporte: " << pasajero["numero_de_pasaporte"] << std::endl;
            std::cout << "Vuelo: " << pasajero["vuelo"] << std::endl;
            std::cout << "Asiento: " << pasajero["asiento"] << std::endl;
            std::cout << "Destino: " << pasajero["destino"] << std::endl;
            std::cout << "Origen: " << pasajero["origen"] << std::endl;
            std::cout << "Equipaje_Facturado: " << pasajero["equipaje_facturado"] << std::endl;
            std::cout << "---------------------------" << std::endl;
            */
            
        }
        // Mostrar todos los pasajeros:
        //colaPasajeros.display();
        cout << "Se Cargaron los Pasajeros correctamente. Press Enter..." << endl;
        // Para detenerse hasta que se presione Enter
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar cualquier entrada previa
        cin.get();  // Esperar hasta que se presione Enter
    } else {
        std::cout << "No se selecciono ningun archivo." << std::endl;
    }
}

void cargarMovimientos() {
    cout << "Cargando Movimientos..." << endl;
    bool validacion = false;
    // Codigo para cargar movimientos
    const char * filterPatterns[] = { "*.txt" };
    const char * filePath = tinyfd_openFileDialog(
        "Seleccione un archivo TXT",  // Título de la ventana
        "",                            // Ruta inicial (vacío significa directorio actual)
        1,                             // Número de filtros
        filterPatterns,                // Filtros de archivos
        NULL,                          // Descripción del filtro
        0                              // Permitir seleccionar múltiples archivos (0: no, 1: sí)
    );

    if (filePath) {
        //std::cout << "Archivo seleccionado: " << filePath << std::endl;
        // manejar el archivo seleccionado

        // Leer el archivo JSON
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return;
        }

        // Leer todo el contenido del archivo en una cadena
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string contenido = buffer.str();
        file.close();

        // Separar las instrucciones por el carácter ';'
        std::vector<std::string> instrucciones;
        std::stringstream ss(contenido);
        std::string instruccion;

        while (std::getline(ss, instruccion, ';')) {
            // Eliminar espacios en blanco al inicio y al final de la instrucción
            instruccion.erase(0, instruccion.find_first_not_of(" \n\r\t"));
            instruccion.erase(instruccion.find_last_not_of(" \n\r\t") + 1);

            if (!instruccion.empty()) {
                instrucciones.push_back(instruccion);
            }
        }

        pilaEquipajes.vaciar();
        ListaEnlazadaDoblePasajeros.vaciar();
        // Mostrar las instrucciones para verificar
        for (const std::string &instr : instrucciones) {
            //std::cout << "Instruccion: " << instr << std::endl;
            /*
            En esta parte se crea lo siguinete:
            cola: pasajeros
            lista doble: psajeros
            pila: equipaje
            */ 
            if(instr == "IngresoEquipajes"){
                //std::cout << "---------------Procesando IngresoEquipajes...----------------" << std::endl;
                //Ingreso de equipaje a la Pila pilaEquipajes
                // Desencolar y almacenar el pasajero
                Pasajeros* desencolado = colaPasajeros.desencolar();
                if (desencolado != nullptr) {
                    // Mostrar la información del pasajero desencolado
                    // Aca se comprueba si el equipaje es mayor a cero
                    if (desencolado->equipaje_facturado > 0){
                        //desencolado->mostrarInfo();
                        pilaEquipajes.push(desencolado);
                    }
                    //Aca se agregan los pasajeros que salgan de la cola 
                    ListaEnlazadaDoblePasajeros.agregar(desencolado);
                }
            }
            else {
                //Aca deben de ir las indtrucciones de: ManteniminetoAviones, Ingreso, N12345
                // Separar las instrucciones por el carácter ','
                std::vector<std::string> partes;
                std::stringstream ss(instr);
                std::string parte;

                while (std::getline(ss, parte, ',')) {
                    // Eliminar espacios en blanco al inicio y al final de cada parte
                    parte.erase(0, parte.find_first_not_of(" \n\r\t"));
                    parte.erase(parte.find_last_not_of(" \n\r\t") + 1);
                    if (!parte.empty()) {
                        partes.push_back(parte);
                    }
                }

                // Verificar que se hayan separado correctamente las partes
                if (partes.size() == 3) {
                    std::string tipoMovimiento = partes[0];
                    std::string accion = partes[1];
                    std::string identificador = partes[2];

                    // Procesar cada tipo de movimiento
                    /*
                    En esta parte se crea lo siguinete:
                    lista circular doble: mantenimiento
                    */ 
                    if (tipoMovimiento == "MantenimientoAviones") {
                        //validacion = true;
                        if (accion == "Ingreso") {
                            // Aca crear las de Ingreso
                            std::cout << "Procesando MantenimientoAviones Ingreso para " << identificador << std::endl;
                            NodoAviones* nodoIngreso = listaAvionesDisponibles.retornarNodo(identificador, "Mantenimiento");
                            Aviones* avionIngreso = new Aviones(nodoIngreso->data->vuelo, nodoIngreso->data->numero_de_registro, nodoIngreso->data->modelo, nodoIngreso->data->fabricante, nodoIngreso->data->ano_fabricacion, nodoIngreso->data->capacidad, nodoIngreso->data->peso_max_despege, nodoIngreso->data->aerolinea, nodoIngreso->data->estado);
                            listaAvionesMantenimiento.insert(avionIngreso);
                            listaAvionesDisponibles.eliminarNodoAvion(identificador);
                        } else if (accion == "Salida") {
                            // Aca crear las de Salida
                            std::cout << "Procesando MantenimientoAviones Salida para " << identificador << std::endl;
                            NodoAviones* nodoSalida = listaAvionesMantenimiento.retornarNodo(identificador, "Disponible");
                            Aviones* avionSalida = new Aviones(nodoSalida->data->vuelo, nodoSalida->data->numero_de_registro, nodoSalida->data->modelo, nodoSalida->data->fabricante, nodoSalida->data->ano_fabricacion, nodoSalida->data->capacidad, nodoSalida->data->peso_max_despege, nodoSalida->data->aerolinea, nodoSalida->data->estado);
                            listaAvionesMantenimiento.eliminarNodoAvion(identificador);
                            listaAvionesDisponibles.insert(avionSalida);
                        } else {
                            std::cerr << "Accion desconocida: " << accion << std::endl;
                        }
                    } 
                    else {
                        std::cerr << "Tipo de movimiento desconocido: " << tipoMovimiento << std::endl;
                    }
                } 
                else {
                    std::cerr << "Formato de instruccion incorrecto: " << instr << std::endl;
                }
            }
        }

        //mostrar la pila
        //pilaEquipajes.printPila();
        //ListaEnlazadaDoblePasajeros.imprimirHaciaDelante();
        ListaEnlazadaDoblePasajeros.ordenar();
        //cout << "-------------------Lista ordenada:-------------" << endl;
        //ListaEnlazadaDoblePasajeros.imprimirHaciaDelante();


        // Mostrar todos los aviones en la lista ya ordenados segun el archivo de movimimientos
        //cout << "-------------------Lista de Aviones actualizada:-------------" << endl;
        //listaAvionesDisponibles.display();
        //listaAvionesMantenimiento.display();
        cout << "Se Cargaron los Movimientos correctamente. Press Enter..." << endl;
        // Para detenerse hasta que se presione Enter
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar cualquier entrada previa
        cin.get();  // Esperar hasta que se presione Enter
    } else {
        std::cout << "No se selecciono ningun archivo." << std::endl;
    }
}


void buscarPasajero(std::string numPasaporte){
    cout << "Cargando Informacion del Pasajero..." << endl;
    //Aca se realiza la busqueda y posteriormente se imprime en consola
    ListaEnlazadaDoblePasajeros.buscarPasaporte(numPasaporte);

    cout << "Se Cargaro el Pasajero correctamente. Press Enter..." << endl;
    // Para detenerse hasta que se presione Enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar cualquier entrada previa
    cin.get();  // Esperar hasta que se presione Enter
}

void generarGrafias(){
    cout << "Generando Grafias..." << endl;
    listaAvionesDisponibles.graficar("Circular_Doble_Dispobibles");
    listaAvionesMantenimiento.graficar("Circular_Doble_Mantenimiento");
    colaPasajeros.graficar();
    pilaEquipajes.graficar();
    ListaEnlazadaDoblePasajeros.graficar();

    cout << "Se Generaron las Grafias correctamente. Press Enter..." << endl;
    // Para detenerse hasta que se presione Enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar cualquier entrada previa
    cin.get();  // Esperar hasta que se presione Enter
}


void vaciarTodasLasListas(){
    cout << "Vaciando las Listas..." << endl;
    listaAvionesDisponibles.vaciar();;
    listaAvionesMantenimiento.vaciar();
    colaPasajeros.vaciar();
    pilaEquipajes.vaciar();
    ListaEnlazadaDoblePasajeros.vaciar();
    cout << "Se Vaciaron las Listas correctamente. Press Enter..." << endl;
    // Para detenerse hasta que se presione Enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar cualquier entrada previa
    cin.get();  // Esperar hasta que se presione Enter
}


int main() {
    int opcion;
    std::string pasaporte;
    do {
        cout << "------------------------MENU-----------------------" << endl;
        cout << "1. Carga de aviones" << endl;//Finalizado
        cout << "2. Carga de pasajeros" << endl;//Finalizado
        cout << "3. Carga de movimientos" << endl;//Faltan los movimintos de aviones
        cout << "4. Consultar pasajeros" << endl;
        cout << "5. Visualizar reporte" << endl;
        cout << "6. Reiniciar Listas" << endl;
        cout << "7. Salir" << endl;
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
                cout << "Ingrese el numero de pasaporte: " << endl;
                cin >> pasaporte;
                buscarPasajero(pasaporte);
                break;
            case 5:
                generarGrafias();
                break;
            case 6:
                vaciarTodasLasListas();
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }

        cout << endl;
    } while(opcion != 7);

    return 0;
}
