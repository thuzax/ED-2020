
#include <iostream>
#include <string>

using namespace std;

#ifndef ELEMENTO
#define ELEMENTO 1

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

#endif