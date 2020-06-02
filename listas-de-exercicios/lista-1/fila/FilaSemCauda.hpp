// Lista encadeada sem ponteiro cauda

#include <iostream>
#include <string>

#include "Elemento.hpp"

using namespace std;

#ifndef LISTA_SEM_CAUDA
#define LISTA_SEM_CAUDA 1

class FilaSemCauda {
    private:
        Elemento* inicio;
    public:
        FilaSemCauda();
        ~FilaSemCauda();

        int remove_inicio();
        void insere_fim(int dado);

};

#endif