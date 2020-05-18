// Heap

#include <iostream>

#include "Noh.hpp"

class Heap {
    private:
        int contador_id;

        Noh** vetor;
        bool crescente;

        int tamanho;
        int tamanho_maximo;

        bool verifica_ordem_anterior(Noh* noh, Noh* anterior);
        bool verifica_ordem_proxima(Noh* noh, Noh* proximo);

        bool heap_vazia();
        bool heap_cheia();
        bool indice_invalido();

        void corrige_subindo(int pos);

    public:
        Heap(int tamanho_maximo, bool crescente = true);
        ~Heap();


        int pos_pai(int pos_filho);
        int pos_direita(int pos_pai);
        int pos_esquerda(int pos_pai);
        
        void adiciona(int dado);
        void set_dado(int id, int dado);
        int remove();


        void imprime();
        void imprime_ordenado();

};