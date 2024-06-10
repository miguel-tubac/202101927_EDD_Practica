#include "Cola.h"
#include <iostream>

//Para generar el grafo, ya que es una cebezera para leer y escrbir archivos:
#include <fstream>
#include <cstdlib>//esta nos permite acceder al sistema y ejucar comandos como si fuera la consola
using namespace std;

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
        std::cout << "La cola esta vacia." << std::endl;
        return;
    }
    Node* actual = frente;
    while (actual != nullptr) {
        actual->data->mostrarInfo();
        actual = actual->next;
    }
}


void Cola::vaciar() {
    while (!isEmpty()) {
        desencolar();
    }
}


void Cola::graficar() {
    if (isEmpty()) {
        std::cout << "La cola esta vacia." << std::endl;
        return;
    }

    ofstream archivo;
    archivo.open("clasesPropias/Grafica2.dot", ios::out);
    //Ahora empezamos a concatenar los datos del ast
    archivo << "digraph G { randir = LR;"<< endl;
    archivo << "label = \"Cola De Pasajeros\";" << std::endl; // Título de la gráfica
    archivo << "labelloc = \"t\";" << std::endl; // Posición del título (t = top)
    archivo << "fontsize = 20;" << std::endl; // Tamaño de la fuente del título
    //Ahora aqui se agregaran los nodos:
    Node* actual = frente;
    std::string concatenado = "";
    while (actual != nullptr) {
        concatenado = "\"Pasaporte : "+actual->data->numero_de_pasaporte +"\n Nombre: "+ actual->data->nombre+"\"";
        archivo << concatenado;
        actual = actual->next;
        if(actual != nullptr){
            archivo << "->";
        }
    }
    archivo << " ; }";//este es el fin del archivo
    archivo.close();

    //Aca se compila el archivo:
    system("dot -Tpng clasesPropias/Grafica2.dot -o ColaRegistro.png");
    
    //Aca para mostrarlo desde el sistema es decir que lo abra el explorador de imagenes
    system("start mspaint ColaRegistro.png");
}