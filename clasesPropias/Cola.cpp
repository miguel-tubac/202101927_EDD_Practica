#include "Cola.h"
#include <iostream>

Cola::Cola() : front(nullptr), rear(nullptr) {}

Cola::~Cola() {
    while (!isEmpty()) {
        desencolar();
    }
}


// Aca se agregan objetos de tipo pasajero a la cola
void Cola::encolar(Pasajeros* pasajero) {
    Node* newNode = new Node(pasajero);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}


// Aca se quitan pasajeros de la cola, es decir (first-in, first-out, primero en entrar, primero en salir).
Pasajeros* Cola::desencolar() {
    if (isEmpty()) {
        std::cerr << "La cola está vacía." << std::endl;
        return nullptr;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    Pasajeros* pasajero = temp->data;
    delete temp;
    return pasajero;
}


// Se comprueba si la cola esta vasilla
bool Cola::isEmpty() const {
    return front == nullptr;
}


//Esto es para mostrar la informacion de la cola
void Cola::display() const {
    if (isEmpty()) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }
    Node* current = front;
    while (current != nullptr) {
        current->data->mostrarInfo();
        current = current->next;
    }
}
