#include "Aviones.hpp"

Aviones::Aviones(std::string v, std::string nr, std::string m, std::string f, int af, int c, int pmd, std::string a, std::string e)
    : vuelo(v), numero_de_registro(nr), modelo(m), fabricante(f), ano_fabricacion(af), capacidad(c), peso_max_despege(pmd), aerolinea(a), estado(e) {}

void Aviones::mostrarInfo() const {
    std::cout << "Vuelo: " << vuelo << std::endl;
    std::cout << "Número de registro: " << numero_de_registro << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Fabricante: " << fabricante << std::endl;
    std::cout << "Año de fabricación: " << ano_fabricacion << std::endl;
    std::cout << "Capacidad: " << capacidad << std::endl;
    std::cout << "Peso máximo de despegue: " << peso_max_despege << std::endl;
    std::cout << "Aerolínea: " << aerolinea << std::endl;
    std::cout << "Estado: " << estado << std::endl;
    std::cout << "---------------------------" << std::endl;
}

