#include "Ferry.h"

int Ferry::añadirCarril(Carril nuevoCarril) {
    if (this->carriles.size() >= this->capacidadCarriles) return -1;
    this->carriles.push_back(nuevoCarril);
}

Ferry::Ferry(char tipo, string nombre, int numeroAutomoviles) {
    if (tipo == 'G') {
        this->capacidadCarriles = 4;
        this->capacidadAutomovilCarril = INF;
    } else {
        this->capacidadAutomovilCarril = numeroAutomoviles;
        this->capacidadCarriles = INF;
    }
    this->nombre = nombre;
}

char Ferry::getTipo() const {
    return tipo;
}

void Ferry::setTipo(char tipo) {
    Ferry::tipo = tipo;
}

const string &Ferry::getNombre() const {
    return nombre;
}

void Ferry::setNombre(const string &nombre) {
    Ferry::nombre = nombre;
}

int Ferry::getCapacidadCarriles() const {
    return capacidadCarriles;
}

void Ferry::setCapacidadCarriles(int capacidadCarriles) {
    Ferry::capacidadCarriles = capacidadCarriles;
}

int Ferry::getCapacidadAutomovilCarril() const {
    return capacidadAutomovilCarril;
}

void Ferry::setCapacidadAutomovilCarril(int capacidadAutomovilCarril) {
    Ferry::capacidadAutomovilCarril = capacidadAutomovilCarril;
}

int Ferry::eliminarAutomovil(int numeroPlaca) {
    // Vamos a mirar por cada uno de los carriles;
    bool flag = false;
    auto it = this->carriles.begin();
    for (; it != this->carriles.end(); it++) {
        // Hay que tener en cuenta que si vamos a buscar un automovil, debemos mantener una stack auxiliar
        // Osino perderíamos la información
        stack<Automovil> copy;
        while (!it->getAutomoviles().empty()) {
            Automovil carro = it->getAutomoviles().top();
            it->getAutomoviles().pop();
            if (carro.getNumeroPlaca() == numeroPlaca) {
                flag = true;
                break;
            }
            copy.push(carro);
        }

        // Esta parte se puede ver como si quisieramos sacar un anillo de una torre de hanoi.

        // Hay que restaurar el stack
        while (!copy.empty()) {
            it->getAutomoviles().push(copy.top());
            copy.pop();
        }

        if (flag) break;
    }
    // Hay que retornar algún codigo para saber si se eliminó algún carro o no.
    if (flag) return 0;

    return -1;
}

int Ferry::agregarAutomovil(Automovil nuevo) {
    auto it = this->carriles.begin();
    bool flag = false;
    for (; it != this->carriles.end(); it++) {
        if (it->getAutomoviles().size() < this->capacidadAutomovilCarril) {
            flag = true;
            it->getAutomoviles().push(nuevo);
            break;
        }
    }

    if (!flag) {
        if (this->carriles.size() == this->capacidadCarriles) return -1; // La capacidad de carriles esta lleno
        Carril n; n.getAutomoviles().push(nuevo);
        this->carriles.push_back(n);
    }

    return 0;
}
