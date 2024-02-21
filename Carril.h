#include <bits/stdc++.h>
#include "Automovil.h"

class Carril {
    private:
        stack<Automovil> automoviles;
    public:
        stack<Automovil> getAutomoviles();
        void setAutomoviles(stack<Automovil> nuevoStack);
};