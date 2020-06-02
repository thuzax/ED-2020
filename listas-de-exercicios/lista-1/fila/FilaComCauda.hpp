// Lista encadeada sem ponteiro cauda

#include <iostream>
#include <string>

#include "Elemento.hpp"

using namespace std;

#ifndef FILA
#define FILA 1


class FilaComCauda {
    private:
        Elemento* inicio;
        Elemento* fim;
    public:
        FilaComCauda();
        ~FilaComCauda();

        void insere_fim(int dado);
        int remove_inicio();

};

#endif