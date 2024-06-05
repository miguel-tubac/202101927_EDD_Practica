#ifndef CIRCULAR_DOUBLY_LINKED_LIST_HPP
#define CIRCULAR_DOUBLY_LINKED_LIST_HPP

#include "Nodo.hpp"

class CircularDoublyLinkedList {
private:
    Nodo* head;

public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();
    void insert(Aviones* avion);
    void display() const;
};

#endif // CIRCULAR_DOUBLY_LINKED_LIST_HPP
