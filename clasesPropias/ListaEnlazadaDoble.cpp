#include "ListaEnlazadaDoble.h"
#include <iostream>

ListaEnlazadaDoble::ListaEnlazadaDoble() : head(nullptr), tail(nullptr) {}

ListaEnlazadaDoble::~ListaEnlazadaDoble() {
    Node3* current = head;
    Node3* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    }
}

void ListaEnlazadaDoble::agregar(Pasajeros* pasajero) {
    Node3* newNode = new Node3(pasajero);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}



void ListaEnlazadaDoble::imprimirHaciaDelante() const {
    Node3* current = head;
    while (current != nullptr) {
        current->data->mostrarInfo();
        current = current->next;
    }
}


bool ListaEnlazadaDoble::isEmpty() const {
    return head == nullptr;
}

//Los ordena de manera sendente a los objetos Pasajeros:
void ListaEnlazadaDoble::ordenar() {
    if (isEmpty() || head->next == nullptr) return; // No hay necesidad de ordenar si la lista está vacía o solo tiene un elemento

    Node3* actual = head->next; // Comenzamos desde el segundo nodo
    while (actual != nullptr) {
        Node3* anterior2 = actual->prev;
        Pasajeros* key = actual->data;
        // Insertar current en la lista ordenada por vuelo y asiento
        while (anterior2 != nullptr && comparar(anterior2->data, key) > 0) {
            anterior2->next->data = anterior2->data;
            anterior2 = anterior2->prev;
        }
        if (anterior2 == nullptr) {
            head->data = key;
        } else {
            anterior2->next->data = key;
        }
        actual = actual->next;
    }
}

// Comparar dos objetos de tipo Pasajeros
int ListaEnlazadaDoble::comparar(Pasajeros* p1, Pasajeros* p2) const {
    // Comparar por numero de vuelo
    int compareVuelo = p1->vuelo.compare(p2->vuelo);
    if (compareVuelo != 0) return compareVuelo;

    // Si los numeros de vuelo son iguales, comparar por numero de asiento
    return p1->asiento.compare(p2->asiento);
}
