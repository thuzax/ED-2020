// Lista

#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP 1


#include "Noh.hpp"
#include "Lista.hpp"

using namespace std;

class ListaEncadeada : public Lista {
    private:
        void remove_noh(Noh* noh, Noh* anterior);

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