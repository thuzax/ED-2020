#include <iostream>

#include "Lista.hpp"

using namespace std;

int main() {
    Lista l = Lista();
    l.adicionaNoh(1);
    l.imprimiLista();
    l.adicionaNoh(2);
    l.imprimiLista();
    l.adicionaNoh(3);
    l.imprimiLista();
    l.adicionaNoh(5);
    l.imprimiLista();
    l.adicionaNoh(7);
    l.imprimiLista();
    l.adicionaNoh(8);
    l.imprimiLista();
    l.adicionaNoh(9);
    l.imprimiLista();

    l.setDado(6, 8);
    l.imprimiLista();
    l.setDado(4, 5);
    l.imprimiLista();

    l.removePorDado(8);
    l.imprimiLista();
    l.adicionaNoh(2);
    l.imprimiLista();
    l.adicionaNoh(5);
    l.imprimiLista();
    l.adicionaNoh(6);
    l.imprimiLista();
    l.adicionaNoh(5);
    l.imprimiLista();
    l.adicionaNoh(8);
    l.imprimiLista();

    l.removePorDado(5);
    l.imprimiLista();
    l.removePorPosicao(0);
    l.imprimiLista();
    l.removePorPosicao(1);
    l.imprimiLista();
    l.removePorPosicao(3);
    l.imprimiLista();
    l.removePorDado(2);
    l.imprimiLista();
    l.removePorPosicao(0);
    l.imprimiLista();

    l.adicionaNoh(0);
    l.imprimiLista();
    l.adicionaNoh(1);
    l.imprimiLista();
    l.adicionaNoh(2);
    l.imprimiLista();



    return 0;

}