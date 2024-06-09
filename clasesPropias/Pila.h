#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Pasajeros.h"

class Node2 {
public:
    Pasajeros* data;
    Node2* next;
    Node2(Pasajeros* data) : data(data), next(nullptr) {}
};

class Pila {
private:
    Node2* arriba;

public:
    Pila() : arriba(nullptr) {}
    ~Pila();

    void push(Pasajeros* data);
    Pasajeros* pop();
    Pasajeros* recorrer() const;
    bool isEmpty() const;
    void printPila() const;
};

#endif // PILA_H
