#include <iostream>

#include "Lista.hpp"
#include "ListaDupla.hpp"

using namespace std;

int main() {
    Lista l = ListaDupla();
    l.adiciona_no_final(1);
    l.imprimi_lista();
    l.adiciona_no_final(2);
    l.imprimi_lista();
    l.adiciona_no_final(3);
    l.imprimi_lista();
    l.adiciona_no_final(5);
    l.imprimi_lista();
    l.adiciona_no_final(7);
    l.imprimi_lista();
    l.adiciona_no_final(8);
    l.imprimi_lista();
    l.adiciona_no_final(9);
    l.imprimi_lista();

    l.set_dado(6, 8);
    l.imprimi_lista();
    l.set_dado(4, 5);
    l.imprimi_lista();
    
    cout << endl;
    cout << l.get_dado_por_posicao(0) << endl;
    cout << l.get_dado_por_posicao(1) << endl;
    cout << l.get_dado_por_posicao(6) << endl;
    cout << endl;

    l.remove_por_dado(8);
    l.imprimi_lista();
    l.adiciona_no_final(2);
    l.imprimi_lista();
    l.adiciona_no_final(5);
    l.imprimi_lista();
    l.adiciona_no_final(6);
    l.imprimi_lista();
    l.adiciona_no_final(5);
    l.imprimi_lista();
    l.adiciona_no_final(8);
    l.imprimi_lista();

    l.remove_por_dado(5);
    l.imprimi_lista();
    l.remove_por_posicao(0);
    l.imprimi_lista();
    l.remove_por_posicao(1);
    l.imprimi_lista();
    l.remove_por_posicao(3);
    l.imprimi_lista();
    l.remove_por_dado(2);
    l.imprimi_lista();
    l.remove_por_posicao(0);
    l.imprimi_lista();

    l.adiciona_no_final(0);
    l.imprimi_lista();
    l.adiciona_no_final(1);
    l.imprimi_lista();
    l.adiciona_no_final(2);
    l.imprimi_lista();



    return 0;

}