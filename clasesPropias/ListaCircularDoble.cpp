#include "ListaCircularDoble.h"
#include <iostream>

ListaCircularDoble::ListaCircularDoble() : head(nullptr) {}

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
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    Nodo* current = head;
    do {
        current->data->mostrarInfo();
        current = current->next;
    } while (current != head);
}