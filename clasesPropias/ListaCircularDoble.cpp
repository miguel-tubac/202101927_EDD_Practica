#include "ListaCircularDoble.h"
#include <iostream>

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
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }
    NodoAviones* actual = inicio;
    do {
        actual->data->mostrarInfo();
        actual = actual->next;
    } while (actual != inicio);
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
