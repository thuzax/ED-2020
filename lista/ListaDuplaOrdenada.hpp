// Lista duplamente encadeada ordenada

#ifndef LISTA_DUPLA_ORDENADA_HPP
#define LISTA_DUPLA_ORDENADA_HPP 1

#include <iostream>

using namespace std;

#include "Noh.hpp"
#include "ListaOrdenada.hpp"

class ListaDuplaOrdenada : public ListaOrdenada {
    private:
        void remove_noh(Noh* noh);
        void aloca_entre_nohs(Noh* noh, Noh* noh_ini, Noh* noh_fim);

    protected:
        virtual bool verifica_ordem_proximo(Noh* noh, Noh* proximo);
        virtual bool verifica_ordem_anterior(Noh* noh, Noh* anterior);
    
    public:
        ListaDuplaOrdenada(bool crescente = true);

        virtual void adiciona(int dado);
        
        virtual void set_dado(int posicao, int dado);
        
        virtual void remove_por_posicao(int posicao);
        virtual void remove_por_dado(int dado);
        
        virtual int get_dado_por_posicao(int posicao);
};

#endif