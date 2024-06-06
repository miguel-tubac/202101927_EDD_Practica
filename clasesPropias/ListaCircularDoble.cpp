#include "ListaCircularDoble.h"
#include <iostream>

ListaCircularDoble::ListaCircularDoble() : head(nullptr) {}

// Definición del constructor de Nodo fuera de la declaración de la clase
Nodo::Nodo(Aviones* a) : data(a), next(nullptr), prev(nullptr) {}

ListaCircularDoble::~ListaCircularDoble() {
    if (head == nullptr) return;
    Nodo* current = head;
    do {
        Nodo* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    } while (current != head);
}

void ListaCircularDoble::insert(Aviones* avion) {
    Nodo* newNode = new Nodo(avion);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Nodo* tail = head->prev;
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
    Nodo* current = head;
    do {
        current->data->mostrarInfo();
        current = current->next;
    } while (current != head);
}


void ListaCircularDoble::buscarYActualizar(std::string identificador, std::string estado) {
    if (head == nullptr) return; //Cuando este vasilla
    Nodo* actual = head; // Comenzamos desde el primer nodo
    do{
        if(actual->data->numero_de_registro == identificador){
            actual->data->estado = estado;
            break;
        }
        actual = actual->next;
    } while (actual != head);
}


void ListaCircularDoble::unirListas(const ListaCircularDoble& lista2, ListaCircularDoble& lista3) {
    // Copiar los elementos de la primera lista
    Nodo* current = head;
    do {
        lista3.insert(current->data);
        current = current->next;
    } while (current != head);

    // Copiar los elementos de la segunda lista
    Nodo* current2 = lista2.head;
    do {
        lista3.insert(current2->data);
        current2 = current2->next;
    } while (current2 != lista2.head);

    //lista3.display();
}


void ListaCircularDoble::recorrer(ListaCircularDoble& lista1, ListaCircularDoble& lista2) const {
    if (head == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    std::cout << "Recorriendo la lista..." << std::endl;

    //lista1.vaciar();
    //lista2.vaciar();

    Nodo* actual = head;
    do {
        if (actual->data != nullptr) {
            std::cout << "Procesando avión con estado: " << actual->data->estado << std::endl;
            if (actual->data->estado == "Mantenimiento") {
                lista2.insert(actual->data);
            } else if (actual->data->estado == "Disponible") {
                lista1.insert(actual->data);
            }
        }
        actual = actual->next;
    } while (actual != head);

    std::cout << "Fin del recorrido." << std::endl;
}




void ListaCircularDoble::vaciar() {
    if (head == nullptr) return;

    std::cout << "Vaciando la lista..." << std::endl;

    Nodo* current = head;
    do {
        Nodo* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    } while (current != head);

    head = nullptr;

    std::cout << "Lista vaciada." << std::endl;
}

