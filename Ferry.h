#include <bits/stdc++.h>
#include "Carril.h"

using namespace std;

class Ferry {
    private:
        list<Carril> carriles;
        char tipo;
        string nombre;
        int capacidadCarriles;
        int capacidadAutomovilCarril;
    public:
        static const int INF = 1e5; // Esto es 100000 -> INF de infinito

        Ferry(char tipo, string nombre, int numeroAutomoviles);

        list<Carril> getCarriles();

        void setCarriles(list<Carril> carril);

        int añadirCarril(Carril nuevoCarril);

        char getTipo() const;

        void setTipo(char tipo);

        const string &getNombre() const;

        void setNombre(const string &nombre);

        int getCapacidadCarriles() const;

        void setCapacidadCarriles(int capacidadCarriles);

        int getCapacidadAutomovilCarril() const;

        void setCapacidadAutomovilCarril(int capacidadAutomovilCarril);

        int agregarAutomovil(Automovil nuevo);

        int eliminarAutomovil(int numeroPlaca);
};