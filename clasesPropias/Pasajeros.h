#ifndef PASAJEROS_H
#define PASAJEROS_H

#include <string>
#include <iostream>

class Pasajeros {
public:
    std::string nombre;
    std::string nacionalidad;
    std::string numero_de_pasaporte;
    std::string vuelo;
    int asiento;
    std::string destino;
    std::string origen;
    int equipaje_facturado;

    Pasajeros(std::string v, std::string nr, std::string m, std::string f, int af, std::string c, std::string pmd, int a);
    void mostrarInfo() const;
};

#endif // PASAJEROS_H