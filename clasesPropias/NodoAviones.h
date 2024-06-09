#ifndef NODOAVIONES_H
#define NODOAVIONES_H

#include "Aviones.h"

class NodoAviones {
public:
    Aviones* data;
    NodoAviones* next;
    NodoAviones* prev;

    NodoAviones(Aviones* a);
};

#endif // NODOAVIONES_Hñ