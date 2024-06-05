#ifndef NODO_HPP
#define NODO_HPP

#include "Aviones.h"

class Nodo {
public:
    Aviones* data;
    Nodo* next;
    Nodo* prev;

    Nodo(Aviones* a);
};

#endif // NODO_HPP