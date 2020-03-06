#include <iostream>

#include "Lista.hpp"

Lista::Lista() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

Lista::~Lista() {
    while (this->inicio != nullptr) {
        Noh* noh = this->inicio;
        this->inicio = noh->get_proximo();
        delete noh;
        noh = nullptr;
    }
    this->inicio = nullptr;
    this->fim = nullptr;
}

bool Lista::lista_vazia() {
    if (this->tamanho == 0) {
        return true;
    }
    return false;
}

bool Lista::posicao_valida(int posicao) {
    if (posicao > -1 and posicao < this->tamanho) {
        return true;
    }
    return false;
}

void Lista::imprime_lista() {
    Noh* noh = this->inicio;
    while(noh != nullptr) {
        cout << noh->get_dado() << " ";
        noh = noh->get_proximo();
    }
    cout << endl;
}