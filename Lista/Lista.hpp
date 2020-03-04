// Lista

#ifndef LISTA_HPP
#define LISTA_HPP 1


#include "Noh.hpp"

using namespace std;

class Lista {
    private:
        void remove_noh(Noh* noh, Noh* anterior);

    protected:
        Noh* inicio;
        Noh* fim;
        int tamanho;

        bool posicao_valida(int posicao);
        bool lista_vazia();

    public:
        Lista();
        ~Lista();

        void adiciona_no_inicio(int dado);
        void adiciona_no_final(int dado);
        void adiciona_na_posicao(int posicao, int dado);
        
        void set_dado(int posicao, int dado);
        
        void remove_por_posicao(int posicao);
        void remove_por_dado(int dado);
        
        int get_dado_por_posicao(int posicao);
        void imprimi_lista(); 

};

#endif