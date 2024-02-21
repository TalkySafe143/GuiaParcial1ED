#include "Carril.h"

stack<Automovil> Carril::getAutomoviles() {
    return this->automoviles;
}

void Carril::setAutomoviles(stack<Automovil> nuevoStack) {
    this->automoviles = nuevoStack;
}
