#include "CircularDoublyLinkedList.hpp"
#include <iostream>

CircularDoublyLinkedList::CircularDoublyLinkedList() : head(nullptr) {}

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
    if (head == nullptr) return;
    Nodo* current = head;
    do {
        Nodo* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    } while (current != head);
}

void CircularDoublyLinkedList::insert(Aviones* avion) {
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

void CircularDoublyLinkedList::display() const {
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
