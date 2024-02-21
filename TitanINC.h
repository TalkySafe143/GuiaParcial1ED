#include <bits/stdc++.h>
#include "Ferry.h"
class TitanINC {
    private:
        list<Ferry> ferrys;
    public:
        int asignarAutomovilesFerryT(queue<Automovil> q);
        void realizarTransbordo();
        void agregarFerry(Ferry nuevo);
        list<Ferry> getFerrys();
        void setFerrys(list<Ferry> ferry);
        list<Ferry>::iterator buscarFerryPorTipo(char tipo);
}