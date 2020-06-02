// Lista encadeada sem ponteiro cauda
#include <iostream>
#include <string>

using namespace std;

#ifndef LISTA_COM_CAUDA
#define LISTA_COM_CAUDA 1


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

class ListaComCauda {
    private:
        Elemento* inicio;
        Elemento* fim;
    public:
        ListaComCauda();
        ~ListaComCauda();

        void insere_inicio(int dado);
        void insere_fim(int dado);

        string get_lista_string();
};

#endif