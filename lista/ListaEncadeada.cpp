#include <iostream>

#include "ListaEncadeada.hpp"


void ListaEncadeada::remove_noh(Noh* noh, Noh* anterior) {
    if (noh->get_proximo() == nullptr) {
        this->fim = anterior;
    }

    if (anterior == nullptr) {
        this->inicio = this->inicio->get_proximo();
    } 
    else {
        anterior->set_proximo(noh->get_proximo());
    }

    delete noh;
    this->tamanho--;
}

void ListaEncadeada::adiciona_no_inicio(int dado) {
    Noh* novo = new Noh(dado);

    if (this->lista_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }

    novo->set_proximo(this->inicio);
    this->inicio = novo;
    this->tamanho++;

    return;

}

void ListaEncadeada::adiciona_no_final(int dado) {
    Noh* novo = new Noh(dado);

    if (this->lista_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }


    this->fim->set_proximo(novo);
    this->fim = novo;
    this->tamanho++;
}

void ListaEncadeada::adiciona_na_posicao(int posicao, int dado) {
    // percorre a listaEncadeada (assim como no set_dado)
    // arruma os ponteiros (verificando inicio e fim)
}

void ListaEncadeada::set_dado(int posicao, int dado) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return;
    }

    Noh* noh = this->inicio;
    while (posicao > 0) {
        posicao--;
        noh = noh->get_proximo();
    }
    noh->set_dado(dado);
}

void ListaEncadeada::remove_por_posicao(int posicao){
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return;
    }

    Noh* noh = this->inicio;

    Noh* anterior = nullptr;
    while (posicao > 0) {
        posicao--;
        anterior = noh;
        noh = noh->get_proximo();
    }


    this->remove_noh(noh, anterior);

}

void ListaEncadeada::remove_por_dado(int dado) {
    if (this->lista_vazia()) {
        return;
    }

    Noh* anterior = nullptr;
    Noh* noh = this->inicio;
    
    while (noh != nullptr) {
        if (noh->get_dado() == dado) {
            Noh* removido = noh;
            noh = noh->get_proximo();
            this->remove_noh(removido, anterior);
        } 
        else {
            anterior = noh;
            noh = noh->get_proximo();
        }
    }
}

int ListaEncadeada::get_dado_por_posicao(int posicao) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return -1;
    }
    
    Noh* noh = this->inicio;

    while (posicao > 0) {
        posicao--;
        noh = noh->get_proximo();
    }
    
    int dado = noh->get_dado();

    return dado;
}