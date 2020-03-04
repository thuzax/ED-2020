// Fila

#ifndef FILA_HPP
#define FILA_HPP 1

#include <iostream>
#include "Noh.hpp"

using namespace std;

class Fila {
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;

        bool fila_vazia();

    public:
        Fila();
        ~Fila();

        void enfileirar(int dado);
        int desenfileirar();
};

#endif