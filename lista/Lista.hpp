// Lista

#ifndef LISTA_HPP
#define LISTA_HPP 1


#include "Noh.hpp"

using namespace std;

class Lista {
    protected:
        Noh* inicio;
        Noh* fim;
        int tamanho;

        bool posicao_valida(int posicao);
        bool lista_vazia();

    public:
        Lista();
        virtual ~Lista();

        virtual void set_dado(int posicao, int dado) = 0;

        virtual void remove_por_posicao(int posicao) = 0;
        virtual void remove_por_dado(int dado) = 0;
        
        virtual int get_dado_por_posicao(int posicao) = 0;
        void imprime_lista(); 

};

#endif