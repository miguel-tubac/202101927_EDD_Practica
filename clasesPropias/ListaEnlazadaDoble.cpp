#include "ListaEnlazadaDoble.h"
#include <iostream>

//Para generar el grafo, ya que es una cebezera para leer y escrbir archivos:
#include <fstream>
#include <cstdlib>//esta nos permite acceder al sistema y ejucar comandos como si fuera la consola
using namespace std;

ListaEnlazadaDoble::ListaEnlazadaDoble() : inicio(nullptr), fin(nullptr) {}

ListaEnlazadaDoble::~ListaEnlazadaDoble() {
    Node3* actual = inicio;
    Node3* nextNode;
    while (actual != nullptr) {
        nextNode = actual->next;
        delete actual->data;
        delete actual;
        actual = nextNode;
    }
}

void ListaEnlazadaDoble::agregar(Pasajeros* pasajero) {
    Node3* newNode = new Node3(pasajero);
    if (fin == nullptr) {
        inicio = fin = newNode;
    } else {
        fin->next = newNode;
        newNode->prev = fin;
        fin = newNode;
    }
}

void ListaEnlazadaDoble::vaciar() {
    if (isEmpty()) return;

    Node3* actual = inicio;
    Node3* nextNode;
    while (actual != nullptr) {
        nextNode = actual->next;
        delete actual->data;
        delete actual;
        actual = nextNode;
    }
    inicio = nullptr;
    fin = nullptr;
}


void ListaEnlazadaDoble::buscarPasaporte(std::string numPasaporte){
    Node3* actual = inicio;
    while (actual != nullptr) {
        if (actual->data->numero_de_pasaporte == numPasaporte){
            actual->data->mostrarInfo();
            return;
        }
        actual = actual->next;
    }
    std::cout << "No se encontro el Pasajero con el numero de Pasaporte: "<< numPasaporte << std::endl;
}


bool ListaEnlazadaDoble::isEmpty() const {
    return inicio == nullptr;
}

//Los ordena de manera sendente a los objetos Pasajeros:
void ListaEnlazadaDoble::ordenar() {
    if (isEmpty() || inicio->next == nullptr) return; // No hay necesidad de ordenar si la lista está vacía o solo tiene un elemento

    Node3* actual = inicio->next; // Comenzamos desde el segundo nodo
    while (actual != nullptr) {
        Node3* anterior2 = actual->prev;
        Pasajeros* key = actual->data;
        // Insertar actual en la lista ordenada por vuelo y asiento
        while (anterior2 != nullptr && comparar(anterior2->data, key) > 0) {
            anterior2->next->data = anterior2->data;
            anterior2 = anterior2->prev;
        }
        if (anterior2 == nullptr) {
            inicio->data = key;
        } else {
            anterior2->next->data = key;
        }
        actual = actual->next;
    }
}

// Comparar dos objetos de tipo Pasajeros
int ListaEnlazadaDoble::comparar(Pasajeros* p1, Pasajeros* p2) const {
    // Comparar por numero de vuelo
    int compareVuelo = p1->vuelo.compare(p2->vuelo);
    if (compareVuelo != 0) return compareVuelo;

    // Si los numeros de vuelo son iguales, comparar por numero de asiento
    return p1->asiento - p2->asiento;
}



void ListaEnlazadaDoble::graficar(){
    if (isEmpty()){
        std::cout << "La Lista Enlazada Doble esta vacia." << std::endl;
        return;
    }

    ofstream archivo;
    archivo.open("clasesPropias/Grafica4.dot", ios::out);
    //Ahora empezamos a concatenar los datos del ast
    archivo << "digraph G { randir = LR;"<< endl;
    archivo << "label = \"Lista Enlazada Doble\";" << std::endl; // Título de la gráfica
    archivo << "labelloc = \"t\";" << std::endl; // Posición del título (t = top)
    archivo << "fontsize = 20;" << std::endl; // Tamaño de la fuente del título
    //Ahora aqui se agregaran los nodos:
    Node3* actual = inicio;
    Node3* repaldo = nullptr;
    std::string concatenado = "";
    while (actual != nullptr) {
        concatenado = "\"Pasaporte: "+actual->data->numero_de_pasaporte +"\nNombre: "+ actual->data->nombre+"\nVuelo: "+actual->data->vuelo+"\nN° Asiento: "+std::to_string(actual->data->asiento)+"\"";
        archivo << concatenado;
        actual = actual->next;
        //Esto es para el ultimo nodo
        if (actual != nullptr){
            archivo << "->";
        }

    }
    actual = fin;
    //cout << "Vuelo: " <<actual->data->vuelo <<endl;
    while (actual != nullptr) {
        concatenado = "\"Pasaporte: "+actual->data->numero_de_pasaporte +"\nNombre: "+ actual->data->nombre+"\nVuelo: "+actual->data->vuelo+"\nN° Asiento: "+std::to_string(actual->data->asiento)+"\"";
        archivo << concatenado;
        actual = actual->prev;
        //Esto es para el ultimo nodo
        if (actual != nullptr){
            archivo << "->";
        }
    }
    //cout << "Fin segundo bucle"<<endl;
    //Aca se cierra el archivo .dot
    archivo << " ; }";//este es el fin del archivo
    archivo.close();

    //Aca se compila el archivo:
    system("dot -Tpng clasesPropias/Grafica4.dot -o Enlazada_Doble.png");
    //Aca para mostrarlo desde el sistema es decir que lo abra el explorador de imagenes
    system("start mspaint Enlazada_Doble.png");
}
