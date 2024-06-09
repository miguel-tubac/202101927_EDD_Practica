#include "ListaCircularDoble.h"
#include <iostream>

ListaCircularDoble::ListaCircularDoble() : head(nullptr) {}

// Definición del constructor de Nodo fuera de la declaración de la clase
NodoAviones::NodoAviones(Aviones* a) : data(a), next(nullptr), prev(nullptr) {}

ListaCircularDoble::~ListaCircularDoble() {
    if (head == nullptr) return;
    NodoAviones* current = head;
    do {
        NodoAviones* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    } while (current != head);
}


void ListaCircularDoble::insert(Aviones* avion) {
    NodoAviones* newNode = new NodoAviones(avion);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        NodoAviones* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void ListaCircularDoble::display() const {
    if (head == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }
    NodoAviones* current = head;
    do {
        current->data->mostrarInfo();
        current = current->next;
    } while (current != head);
}



NodoAviones* ListaCircularDoble::retornarNodo(std::string registro, std::string estado) {
    if (head == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return nullptr;
    }

    NodoAviones* actual = head;
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
    } while (actual != head);

    std::cout << "No se encontro el numero de registro Ingresado." << std::endl;
    return nullptr;
}


// Método para eliminar un nodo por valor
void ListaCircularDoble::eliminarNodoAvion(std::string registro) {
    if (head == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }
    
    NodoAviones* actual = head;
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

                if (actual == head) { // Si el nodo a eliminar es el head
                    head = actual->next;
                    //std::cout << "El nodo eliminado es el head. Nuevo head: " << head->data->numero_de_registro << std::endl;
                }
            } else { // Único nodo en la lista
                head = nullptr;
                //std::cout << "Eliminando el unico nodo en la lista." << std::endl;
            }

            // Eliminar los datos del nodo pero no el nodo mismo
            delete actual->data;
            //actual->data = nullptr;
            delete actual;
            return;
        }
        actual = actual->next;
    } while (actual != head);

    // Si no se encontró el nodo, no hacer nada
    std::cout << "No se encontro el nodo con el registro: " << registro << std::endl;
}
