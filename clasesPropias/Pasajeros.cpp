#include "Pasajeros.h"

Pasajeros::Pasajeros(std::string v, std::string nr, std::string m, std::string f, std::string af, std::string c, std::string pmd, int a)
    : nombre(v), nacionalidad(nr), numero_de_pasaporte(m), vuelo(f), asiento(af), destino(c), origen(pmd), equipaje_facturado(a) {}

void Pasajeros::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Nacionalidad: " << nacionalidad << std::endl;
    std::cout << "Numero_De_Pasaporte: " << numero_de_pasaporte << std::endl;
    std::cout << "Vuelo: " << vuelo << std::endl;
    std::cout << "Asiento: " << asiento << std::endl;
    std::cout << "Destino: " << destino << std::endl;
    std::cout << "Origen: " << origen << std::endl;
    std::cout << "Equipaje_Facturado: " << equipaje_facturado << std::endl;
    std::cout << "---------------------------" << std::endl;
}