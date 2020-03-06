#include <iostream>

#include "Lista.hpp"
#include "ListaEncadeada.hpp"
#include "ListaDupla.hpp"
#include "ListaOrdenada.hpp"
#include "ListaDuplaOrdenada.hpp"

using namespace std;

void teste_lista_encadeada(ListaEncadeada* l) {
    l->adiciona_no_final(1);
    l->imprime_lista();
    l->adiciona_no_final(2);
    l->imprime_lista();
    l->adiciona_no_final(3);
    l->imprime_lista();
    l->adiciona_no_final(5);
    l->imprime_lista();
    l->adiciona_no_final(7);
    l->imprime_lista();
    l->adiciona_no_final(8);
    l->imprime_lista();
    l->adiciona_no_final(9);
    l->imprime_lista();

    l->set_dado(6, 8);
    l->imprime_lista();
    l->set_dado(4, 5);
    l->imprime_lista();
    
    cout << endl;
    cout << l->get_dado_por_posicao(0) << endl;
    cout << l->get_dado_por_posicao(1) << endl;
    cout << l->get_dado_por_posicao(6) << endl;
    cout << endl;

    l->remove_por_dado(8);
    l->imprime_lista();

    l->adiciona_no_final(2);
    l->imprime_lista();
    l->adiciona_no_final(5);
    l->imprime_lista();
    l->adiciona_no_final(6);
    l->imprime_lista();
    l->adiciona_no_final(5);
    l->imprime_lista();
    l->adiciona_no_final(8);
    l->imprime_lista();

    l->remove_por_dado(5);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();
    l->remove_por_posicao(1);
    l->imprime_lista();
    l->remove_por_posicao(3);
    l->imprime_lista();
    l->remove_por_dado(2);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();

    l->adiciona_no_final(0);
    l->imprime_lista();
    l->adiciona_no_final(1);
    l->imprime_lista();
    l->adiciona_no_final(2);
    l->imprime_lista();

    l->adiciona_no_inicio(3);
    l->imprime_lista();
    l->adiciona_no_inicio(4);
    l->imprime_lista();

    cout << "========================================================" << endl;
}

void teste_lista_encadeada() {
    ListaEncadeada* l = new ListaEncadeada();
    teste_lista_encadeada(l);
    delete l;
}

void teste_lista_dupla() {
    ListaEncadeada* l = new ListaDupla();
    teste_lista_encadeada(l);
    delete l;
}


void teste_lista_ordenada(ListaOrdenada* l) {
    l->adiciona(1);
    l->imprime_lista();
    l->adiciona(2);
    l->imprime_lista();
    l->adiciona(1);
    l->imprime_lista();
    l->adiciona(3);
    l->imprime_lista();
    l->adiciona(1);
    l->imprime_lista();
    l->adiciona(4);
    l->imprime_lista();
    l->adiciona(5);
    l->imprime_lista();
    l->adiciona(6);
    l->imprime_lista();
    l->adiciona(3);
    l->imprime_lista();
    l->adiciona(4);
    l->imprime_lista();
    l->adiciona(7);
    l->imprime_lista();
    l->adiciona(6);
    l->imprime_lista();

    cout << endl;

    l->set_dado(1, 4);
    l->imprime_lista();
    l->set_dado(6, 2);
    l->imprime_lista();
    l->set_dado(8, 0);
    l->imprime_lista();
    l->set_dado(0, -5);
    l->imprime_lista();
    l->set_dado(11, 12);
    l->imprime_lista();
    l->set_dado(10, 9);
    l->imprime_lista();
    l->set_dado(0, 6);
    l->imprime_lista();
    l->set_dado(11, 3);
    l->imprime_lista();
    l->set_dado(0, 20);
    l->imprime_lista();
    l->set_dado(11, -7);
    l->imprime_lista();
    
    cout << endl;
    
    l->adiciona(-10);
    l->adiciona(21);
    l->adiciona(8);
    l->imprime_lista();
    
    cout << endl;

    l->remove_por_posicao(0);
    l->imprime_lista();
    
    cout << endl;

    l->set_dado(0, 10);
    l->imprime_lista();
    
    cout << endl;

    l->remove_por_posicao(8);
    l->imprime_lista();
    
    cout << endl;
    
    l->adiciona(12);
    l->adiciona(-20);
    l->adiciona(32);
    l->imprime_lista();

    cout << endl;

    l->remove_por_posicao(2);
    l->imprime_lista();
    l->remove_por_posicao(3);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();
    l->remove_por_posicao(2);
    l->imprime_lista();
    l->remove_por_posicao(3);
    l->imprime_lista();
    l->remove_por_posicao(2);
    l->imprime_lista();
    l->remove_por_posicao(1);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();
    l->remove_por_posicao(1);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();
    l->remove_por_posicao(3);
    l->imprime_lista();
    l->remove_por_posicao(3);
    l->imprime_lista();
    l->remove_por_posicao(3);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();
    l->remove_por_posicao(1);
    l->imprime_lista();
    l->remove_por_posicao(0);
    l->imprime_lista();
    
    
    
}

// void teste_lista_ordenada() {
//     ListaOrdenada* l = new ListaOrdenada();
//     teste_lista_encadeda_ordenada(l);
//     delete l;
// }

void teste_lista_dupla_ordenada() {
    ListaOrdenada* l = new ListaDuplaOrdenada(false);
    teste_lista_ordenada(l);
    delete l;
}


int main() {
    // teste_lista_encadeada();
    // teste_lista_dupla();
    teste_lista_dupla_ordenada();

    return 0;

}