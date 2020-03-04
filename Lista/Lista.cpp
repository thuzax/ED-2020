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
        this->inicio = noh->getProximo();
        delete noh;
        noh = nullptr;
    }
    this->inicio = nullptr;
    this->fim = nullptr;
}


void Lista::adicionaNoh(int dado) {
    Noh* novo = new Noh(dado);
    this->tamanho++;

    if (this->inicio == nullptr) {
        this->inicio = novo;
        this->fim = novo;
        return;
    }

    this->fim->setProximo(novo);
    this->fim = novo;
}

void Lista::setDado(int posicao, int dado) {
    Noh* noh = this->inicio;
    while (posicao > 0) {
        posicao--;
        noh = noh->getProximo();
    }
    noh->setDado(dado);
}

void Lista::removePorPosicao(int posicao){
    if (posicao < 0 or posicao >= this->tamanho) {
        cout << "ERRO" << endl;
        return;
    }

    Noh* noh = this->inicio;
    this->tamanho--;

    Noh* anterior = nullptr;
    while (posicao > 0) {
        posicao--;
        anterior = noh;
        noh = noh->getProximo();
    }


    if (anterior == nullptr) {
        this->inicio = this->inicio->getProximo();
    }

    if (noh->getProximo() == nullptr) {
        this->fim = anterior;
    }

    if (anterior != nullptr) {
        anterior->setProximo(noh->getProximo());
    }
    

    delete noh;

}

void Lista::removePorDado(int dado) {
    if (this->tamanho == 0) {
        return;
    }

    Noh* anterior = nullptr;
    Noh* noh = this->inicio;
    
    while (noh != nullptr) {
        if (noh->getDado() == dado) {
            if (noh->getProximo() == nullptr) {
                this->fim = anterior;
            }

            if (anterior == nullptr) {
                this->inicio = this->inicio->getProximo();
            } else {
                anterior->setProximo(noh->getProximo());
            }

            Noh* removido = noh;
            noh = noh->getProximo();
            delete removido;
            tamanho--;
        } else {
            anterior = noh;
            noh = noh->getProximo();
        }
    }
}

int Lista::getDadoPorPosicao(int posicao) {
    return 0;
}

void Lista::imprimiLista() {
    Noh* noh = this->inicio;
    while(noh != nullptr) {
        cout << noh->getDado() << " ";
        noh = noh->getProximo();
    }
    cout << endl;
}