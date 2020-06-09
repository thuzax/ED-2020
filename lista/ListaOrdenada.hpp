// Lista ordenada

#ifndef LISTA_ORDENADA_HPP
#define LISTA_ORDENADA_HPP 1

#include <iostream>

#include "Noh.hpp"
#include "Lista.hpp"

using namespace std;

class ListaOrdenada : public Lista {
    protected:
        bool crescente;

        virtual bool verifica_ordem_proximo(Noh* noh, Noh* proximo);
        virtual bool verifica_ordem_anterior(Noh* noh, Noh* anterior);


    public:
        ListaOrdenada(bool crescente = true);

        virtual void adiciona(int dado);
        virtual void remove_por_posicao(int posicao);
        virtual void remove_por_dado(int dado);
        virtual void set_dado(int posicao, int dado);
        virtual int get_dado_por_posicao(int posicao);

};


#endif