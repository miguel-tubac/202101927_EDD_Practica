#ifndef COLA_H
#define COLA_H

#include "Pasajeros.h"

class Node {
public:
    Pasajeros* data;
    Node* next;
    
    Node(Pasajeros* data) : data(data), next(nullptr) {}
};

class Cola {
private:
    Node* frente;
    Node* ultimo;

public:
    Cola();
    ~Cola();
    void encolar(Pasajeros* avion);
    Pasajeros* desencolar();
    bool isEmpty() const;
    void display() const;
    void graficar();
    void vaciar();
};

#endif // COLA_H
