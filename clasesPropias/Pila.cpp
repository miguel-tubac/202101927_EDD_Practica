#include "Pila.h"

//Para generar el grafo, ya que es una cebezera para leer y escrbir archivos:
#include <fstream>
#include <cstdlib>//esta nos permite acceder al sistema y ejucar comandos como si fuera la consola
using namespace std;

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


void Pila::graficar(){
    if (isEmpty()) {
        std::cerr << "La Pila de Equpaje se encuantra vacia." << std::endl;
        return;
    }

    ofstream archivo;
    archivo.open("clasesPropias/Grafica3.dot", ios::out);
    //Ahora empezamos a concatenar los datos del ast
    archivo << "digraph G { randir = LR;"<< endl;
    archivo << "label = \"Pila De Equipaje\";" << std::endl; // Título de la gráfica
    archivo << "labelloc = \"t\";" << std::endl; // Posición del título (t = top)
    archivo << "fontsize = 20;" << std::endl; // Tamaño de la fuente del título
    //Ahora aqui se agregaran los nodos:
    Node2* actual = arriba;
    std::string concatenado = "";
    while (actual != nullptr) {
        concatenado = "\"Pasaporte : "+actual->data->numero_de_pasaporte +"\n N° Equipaje: "+ std::to_string(actual->data->equipaje_facturado) +"\"";
        archivo << concatenado;
        actual = actual->next;
        if(actual != nullptr){
            archivo << "->";
        }
    }
    archivo << " ; }";//este es el fin del archivo
    archivo.close();

    //Aca se compila el archivo:
    system("dot -Tpng clasesPropias/Grafica3.dot -o PilaEquipaje.png");
    
    //Aca para mostrarlo desde el sistema es decir que lo abra el explorador de imagenes
    system("start mspaint PilaEquipaje.png");
}
