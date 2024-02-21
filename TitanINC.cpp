#include "TitanINC.h"

int TitanINC::asignarAutomovilesFerryT(queue<Automovil> q) {
    // Vamos a buscar un ferry que sea General (T)
    auto it = this->ferrys.begin();
    for (; it != this->ferrys.end(); it++) {
        if (it->getTipo() == 'G') break;
    }

    // Basta con hacer el break porque si encontramos algún ferry ya va a estar en el iterador
    if (it == this->ferrys.end()) return -1; // Si es .end() quiere decir que no hay ferrys de tipo general.

    while (!q.empty()) {
        it->agregarAutomovil(q.front()); // El ferry que estamos agregando el vehículo ya tiene toda la logica
        q.pop();
    }

    return 0;
}

void TitanINC::realizarTransbordo() {
    auto it = this->ferrys.begin();

    for (; it != this->ferrys.end(); it++) { // Vamos a ir por cada ferry
        if (it->getTipo() == 'G') { // Buscando los generales (T)
            auto itCarril = it->getCarriles().begin(); // Vamos a ir por todos los carriles de los generales
            for (; itCarril != it->getCarriles().end(); itCarril++) {
                while (!itCarril->getAutomoviles().empty()) { // A cada carril lo vamos a liberar de todos los carros contenidos
                    Automovil carro = itCarril->getAutomoviles().top();
                    itCarril->getAutomoviles().pop();
                    // Se usa la utilidad para buscar un ferry por tipo
                    auto itFerrySelected = this->buscarFerryPorTipo(carro.getDestino());
                    if (itFerrySelected == this->ferrys.end() || carro.getDestino() == 'T') continue;
                    // Si no hay ferrys de ese tipo que se esta buscando o si el carro se queda en Tenerife entonces no se agrega
                    itFerrySelected->agregarAutomovil(carro);
                }
            }
        }
    }
}

void TitanINC::agregarFerry(Ferry nuevo) {
    this->ferrys.push_back(nuevo);
}

list<Ferry>::iterator TitanINC::buscarFerryPorTipo(char tipo) {
    auto it = this->ferrys.begin();
    for (; it != this->ferrys.end(); it++) {
        if (it->getTipo() == tipo) return it;
    }

    return it;
}
