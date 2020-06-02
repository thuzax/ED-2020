// Lista encadeada sem ponteiro cauda
#include <iostream>
#include <string>

using namespace std;

#ifndef LISTA_SEM_CAUDA
#define LISTA_SEM_CAUDA 1


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

class ListaSemCauda {
    private:
        Elemento* inicio;
    public:
        ListaSemCauda();
        ~ListaSemCauda();

        void insere_inicio(int dado);
        void insere_fim(int dado);

        string get_lista_string();
};

#endif