#ifndef LISTAENLAZADADOBLE_H
#define LISTAENLAZADADOBLE_H
#include "Pasajeros.h"

class Node3 {
public:
    Pasajeros* data;
    Node3* next;
    Node3* prev;

    Node3(Pasajeros* data) : data(data), next(nullptr), prev(nullptr) {}
};

class ListaEnlazadaDoble {
private:
    Node3* inicio;
    Node3* fin;

public:
    ListaEnlazadaDoble();
    ~ListaEnlazadaDoble();
    void agregar(Pasajeros* pasajero);
    void imprimirHaciaDelante() const;
    bool isEmpty() const;
    void ordenar();
    int comparar(Pasajeros* p1, Pasajeros* p2) const;
    void buscarPasaporte(std::string numPasaporte);
};

#endif // LISTAENLAZADADOBLE_H
