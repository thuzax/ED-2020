
#include "Pilha.hpp"

Pilha::Pilha() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

Pilha::~Pilha() {
    Noh* noh = this->fim;
    while (noh != nullptr) {
        this->fim = this->inicio->get_anterior();
        delete noh;
        noh = this->fim;
    }
}

bool Pilha::pilha_vazia() {
    return (this->tamanho == 0);
}

void Pilha::empilhar(int dado) {
    Noh* novo = new Noh(dado);

    if (this->pilha_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }

    novo->set_anterior(this->fim);
    this->fim = novo;
    this->tamanho++;

}

int Pilha::desempilhar() {
    if (this->pilha_vazia()) {
        cout << "Pilha vazia" << endl;
        return -1;
    }

    int dado = this->fim->get_dado();
    
    Noh* noh = this->fim;
    this->fim = this->fim->get_anterior();
    
    delete noh;
    this->tamanho--;

    return dado;

}