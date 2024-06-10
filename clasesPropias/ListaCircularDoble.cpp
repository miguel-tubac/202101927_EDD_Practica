#include "ListaCircularDoble.h"
#include <iostream>

//Para generar el grafo, ya que es una cebezera para leer y escrbir archivos:
#include <fstream>
#include <cstdlib>//esta nos permite acceder al sistema y ejucar comandos como si fuera la consola

using namespace std;

ListaCircularDoble::ListaCircularDoble() : inicio(nullptr) {}

// Definición del constructor de Nodo fuera de la declaración de la clase
NodoAviones::NodoAviones(Aviones* a) : data(a), next(nullptr), prev(nullptr) {}

ListaCircularDoble::~ListaCircularDoble() {
    if (inicio == nullptr) return;
    NodoAviones* actual = inicio;
    do {
        NodoAviones* nextNode = actual->next;
        delete actual->data;
        delete actual;
        actual = nextNode;
    } while (actual != inicio);
}


void ListaCircularDoble::insert(Aviones* avion) {
    NodoAviones* newNode = new NodoAviones(avion);
    if (inicio == nullptr) {
        inicio = newNode;
        inicio->next = inicio;
        inicio->prev = inicio;
    } else {
        NodoAviones* cola = inicio->prev;
        cola->next = newNode;
        newNode->prev = cola;
        newNode->next = inicio;
        inicio->prev = newNode;
    }
}

void ListaCircularDoble::display() const {
    if (inicio == nullptr) {
        std::cout << "La Lista Curcular Doble esta vacia." << std::endl;
        return;
    }
    NodoAviones* actual = inicio;
    do {
        actual->data->mostrarInfo();
        actual = actual->next;
    } while (actual != inicio);
}

void ListaCircularDoble::vaciar() {
    if (inicio == nullptr) return;
    NodoAviones* actual = inicio;
    do {
        NodoAviones* nextNode = actual->next;
        delete actual->data;
        delete actual;
        actual = nextNode;
    } while (actual != inicio);
    inicio = nullptr;
}


void ListaCircularDoble::graficar(std::string nombre){
    if (inicio == nullptr) {
        std::cout << "La Lista Curcular Doble esta vacia." << std::endl;
        return;
    }

    ofstream archivo;
    archivo.open("clasesPropias/Grafica1.dot", ios::out);
    //Ahora empezamos a concatenar los datos del ast
    archivo << "digraph G { randir = LR;"<< endl;
    archivo << "label = \""+nombre+"\";" << std::endl; // Título de la gráfica
    archivo << "labelloc = \"t\";" << std::endl; // Posición del título (t = top)
    archivo << "fontsize = 20;" << std::endl; // Tamaño de la fuente del título
    //Ahora aqui se agregaran los nodos:
    NodoAviones* actual = inicio;
    std::string concatenado = "";
    do {
        concatenado = "\"Registro: "+actual->data->numero_de_registro +"\nEstado: "+ actual->data->estado+"\"";
        archivo << concatenado;
        archivo << "->";
        actual = actual->next;
        //Esto es para el ultimo nodo
        if (actual == inicio){
            concatenado = "\"Registro: "+actual->data->numero_de_registro +"\nEstado: "+ actual->data->estado+"\"";
            archivo << concatenado;
            archivo << "->";
        }
    } while (actual != inicio);

    //Aca lo recorremos hacia atras para generar las flechas que indiquen la direccion contraria:
    actual = actual->prev;
    do {
        concatenado = "\"Registro: "+actual->data->numero_de_registro +"\nEstado: "+ actual->data->estado+"\"";
        archivo << concatenado;
        archivo << "->";
        actual = actual->prev;
        //Esto es para el ultimo nodo
        if (actual == inicio){
            concatenado = "\"Registro: "+actual->data->numero_de_registro +"\nEstado: "+ actual->data->estado+"\"";
            archivo << concatenado;
        }
    } while (actual != inicio);
    //Aca se cierra el archivo .dot
    archivo << " ; }";//este es el fin del archivo
    archivo.close();

    //Aca se compila el archivo:
    std::string creacion = "dot -Tpng clasesPropias/Grafica1.dot -o "+nombre+".png";
    //system("dot -Tpng clasesPropias/Grafica1.dot -o ListaCircularDoble.jpg");
    system(creacion.c_str());
    //Aca para mostrarlo desde el sistema es decir que lo abra el explorador de imagenes
    std::string comando = "start mspaint "+nombre+".png";
    system(comando.c_str());
    
}


NodoAviones* ListaCircularDoble::retornarNodo(std::string registro, std::string estado) {
    if (inicio == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return nullptr;
    }

    NodoAviones* actual = inicio;
    NodoAviones* nodoTemporal = nullptr;
    do {
        //std::cout << "Revisando nodo con registro: " << actual->data->numero_de_registro << std::endl;
        if (actual->data->numero_de_registro == registro) {
            actual->data->estado = estado;
            // Guardar el nodo a retornar antes de modificar punteros
            nodoTemporal = actual;
            //std::cout << "Fin de la funcion retornoNodo" << std::endl;
            return nodoTemporal;
        }
        actual = actual->next;
    } while (actual != inicio);

    std::cout << "No se encontro el numero de registro Ingresado." << std::endl;
    return nullptr;
}


// Método para eliminar un nodo por valor
void ListaCircularDoble::eliminarNodoAvion(std::string registro) {
    if (inicio == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }
    
    NodoAviones* actual = inicio;
    //NodoAviones* nodoAEliminar = nullptr;
    //std::cout << "inicio del eliminarNodoAvion." << std::endl;
    // Busca el nodo que contiene el valor
    do {
        if (actual->data->numero_de_registro == registro) {
            //std::cout << "Nodo encontrado." << std::endl;
            //nodoAEliminar = actual;

            if (actual->next != actual) { // Más de un nodo en la lista
                actual->prev->next = actual->next;
                actual->next->prev = actual->prev;
                //std::cout << "Reorganizando punteros, mas de un nodo en la lista." << std::endl;

                if (actual == inicio) { // Si el nodo a eliminar es el head
                    inicio = actual->next;
                    //std::cout << "El nodo eliminado es el head. Nuevo head: " << head->data->numero_de_registro << std::endl;
                }
            } else { // Único nodo en la lista
                inicio = nullptr;
                //std::cout << "Eliminando el unico nodo en la lista." << std::endl;
            }

            // Eliminar los datos del nodo pero no el nodo mismo
            delete actual->data;
            //actual->data = nullptr;
            delete actual;
            return;
        }
        actual = actual->next;
    } while (actual != inicio);

    // Si no se encontró el nodo, no hacer nadinicio
}
