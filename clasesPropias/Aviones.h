#ifndef AVIONES_HPP
#define AVIONES_HPP

#include <string>
#include <iostream>

class Aviones {
public:
    std::string vuelo;
    std::string numero_de_registro;
    std::string modelo;
    std::string fabricante;
    int ano_fabricacion;
    int capacidad;
    int peso_max_despege;
    std::string aerolinea;
    std::string estado;

    Aviones(std::string v, std::string nr, std::string m, std::string f, int af, int c, int pmd, std::string a, std::string e);
    void mostrarInfo() const;
};

#endif // AVIONES_HPP
