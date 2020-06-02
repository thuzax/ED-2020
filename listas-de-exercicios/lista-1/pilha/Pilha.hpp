// Lista encadeada sem ponteiro cauda
#include <iostream>
#include <string>

using namespace std;

#ifndef PILHA
#define PILHA 1


class Elemento {
    private:
        int dado;
        Elemento* proximo;
    public:
        Elemento(int dado);
        void set_proximo(Elemento* proximo);
        int get_dado();
        Elemento* get_proximo();
};

class Pilha {
    private:
        Elemento* inicio;
    public:
        Pilha();
        ~Pilha();

        void insere_na_pilha(int dado);
        int remove_da_pilha();

};

#endif