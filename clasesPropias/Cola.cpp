#include "Cola.h"
#include <iostream>

Cola::Cola() : frente(nullptr), ultimo(nullptr) {}

Cola::~Cola() {
    while (!isEmpty()) {
        desencolar();
    }
}


// Aca se agregan objetos de tipo pasajero a la cola
void Cola::encolar(Pasajeros* pasajero) {
    Node* newNode = new Node(pasajero);
    if (ultimo == nullptr) {
        frente = ultimo = newNode;
    } else {
        ultimo->next = newNode;
        ultimo = newNode;
    }
}


// Aca se quitan pasajeros de la cola, es decir (first-in, first-out, primero en entrar, primero en salir).
Pasajeros* Cola::desencolar() {
    if (isEmpty()) {
        std::cerr << "La cola esta vacia." << std::endl;
        return nullptr;
    }
    Node* temp = frente;
    frente = frente->next;
    if (frente == nullptr) {
        ultimo = nullptr;
    }
    Pasajeros* pasajero = temp->data;
    delete temp;
    return pasajero;
}


// Se comprueba si la cola esta vasilla
bool Cola::isEmpty() const {
    return frente == nullptr;
}


//Esto es para mostrar la informacion de la cola
void Cola::display() const {
    if (isEmpty()) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }
    Node* current = frente;
    while (current != nullptr) {
        current->data->mostrarInfo();
        current = current->next;
    }
}
