#ifndef CIRCULAR_DOUBLY_LINKED_LIST_HPP
#define CIRCULAR_DOUBLY_LINKED_LIST_HPP

#include "Nodo.h"

class ListaCircularDoble {
private:
    Nodo* head;

public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    void insert(Aviones* avion);
    void display() const;
};

#endif // CIRCULAR_DOUBLY_LINKED_LIST_HPP