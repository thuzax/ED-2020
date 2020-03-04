// Pilha

#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>

#include "Noh.hpp"

using namespace std;

class Pilha {
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;

        bool pilha_vazia();
    
    public:
        Pilha();
        ~Pilha();

        void empilhar(int dado);
        int desempilhar();
};


#endif