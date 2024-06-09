#include "Pila.h"

// Destructor para liberar la memoria utilizada por la pila
Pila::~Pila() {
    while (!isEmpty()) {
        pop();
    }
}

// Función para agregar un elemento a la pila
void Pila::push(Pasajeros* data) {
    Node2* newNode = new Node2(data);
    newNode->next = arriba;
    arriba = newNode;
}

// Función para quitar un elemento de la pila
Pasajeros* Pila::pop() {
    if (isEmpty()) {
        std::cerr << "Error: Intento de pop en una pila vacía." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa debido al error
    }
    Node2* temp = arriba;
    arriba = arriba->next;
    Pasajeros* poppedData = temp->data;
    delete temp;
    return poppedData;
}

// Función para obtener el elemento superior de la pila sin quitarlo
Pasajeros* Pila::recorrer() const {
    if (isEmpty()) {
        std::cerr << "Error: Intento de recorrer en una pila vacia." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa debido al error
    }
    return arriba->data;
}

// Función para verificar si la pila está vacía
bool Pila::isEmpty() const {
    return arriba == nullptr;
}

// Función para imprimir los elementos de la pila
void Pila::printPila() const {
    Node2* actual = arriba;
    while (actual != nullptr) {
        actual->data->mostrarInfo(); // Asumiendo que Aviones tiene operador <<
        actual = actual->next;
    }
}
