// Lista duplamente encadeada

#ifndef LISTA_DUPLA_HPP
#define LISTA_DUPLA_HPP 1

#include "Noh.hpp"
#include "ListaEncadeada.hpp"

using namespace std;

class ListaDupla : public ListaEncadeada {
    protected:
        void remove_noh(Noh* noh);

    public:
        virtual void adiciona_no_inicio(int dado);
        virtual void adiciona_no_final(int dado);
        virtual void adiciona_na_posicao(int posicao, int dado);
        
        virtual void set_dado(int posicao, int dado);
        
        virtual void remove_por_posicao(int posicao);
        virtual void remove_por_dado(int dado);

        virtual int get_dado_por_posicao(int posicao);
};

#endif