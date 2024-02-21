#include <iostream>
using namespace std;
class Automovil {
    private:
        int numeroPlaca;
        string modelo;
        char destino;
    public:
        int getNumeroPlaca();
        void setNumeroPlaca(int numPlaca);
        char getDestino();
        void setDestino(char destino);
        string getModelo();
        void setModelo(string modelo);
}