#ifndef LISTA_CIRCULAR_DOBLE_H
#define LISTA_CIRCULAR_DOBLE_H

#include "Aviones.h"

class Nodo {
public:
    Aviones* data;
    Nodo* next;
    Nodo* prev;

    Nodo(Aviones* a);
};

class ListaCircularDoble {
private:
    Nodo* head;

public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    void insert(Aviones* avion);
    void display() const;
    void vaciar();
    void buscarYActualizar(std::string identificador, std::string estado);
    void unirListas( const ListaCircularDoble& lista2, ListaCircularDoble& lista3);
    void recorrer(ListaCircularDoble& lista1, ListaCircularDoble& lista2) const;
};

#endif // CIRCULAR_DOUBLY_LINKED_LIST_HPP