#ifndef LISTA_CIRCULAR_DOBLE_H
#define LISTA_CIRCULAR_DOBLE_H

#include "Aviones.h"
#include "NodoAviones.h"

class ListaCircularDoble {
private:
    NodoAviones* inicio;

public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    void insert(Aviones* avion);
    void display() const;
    NodoAviones* retornarNodo(std::string registro, std::string estado);
    void eliminarNodoAvion(std::string registro);
    void graficar(std::string nombre);
    void vaciar();
};


#endif // CIRCULAR_DOUBLY_LINKED_LIST_H