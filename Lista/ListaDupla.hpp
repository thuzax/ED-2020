// Lista duplamente encadeada

#ifndef LISTA_DUPLA_HPP
#define LISTA_DUPLA_HPP 1

#include "Noh.hpp"
#include "Lista.hpp"

using namespace std;

class ListaDupla : public Lista {
    protected:
        void remove_noh(Noh* noh);

    public:
        void adiciona_no_inicio(int dado);
        void adiciona_no_final(int dado);
        void adiciona_na_posicao(int posicao, int dado);
        
        void set_dado(int posicao, int dado);
        
        void remove_por_posicao(int posicao);
        void remove_por_dado(int dado);

        int get_dado_por_posicao(int posicao);
};

#endif