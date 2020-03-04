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

void Lista::remove_noh(Noh* noh, Noh* anterior) {
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

void Lista::adiciona_no_inicio(int dado) {
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

void Lista::adiciona_no_final(int dado) {
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

void Lista::adiciona_na_posicao(int posicao, int dado) {
    // percorre a lista (assim como no set_dado)
    // arruma os ponteiros (verificando inicio e fim)
}

void Lista::set_dado(int posicao, int dado) {
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

void Lista::remove_por_posicao(int posicao){
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

void Lista::remove_por_dado(int dado) {
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

int Lista::get_dado_por_posicao(int posicao) {
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

void Lista::imprimi_lista() {
    Noh* noh = this->inicio;
    while(noh != nullptr) {
        cout << noh->get_dado() << " ";
        noh = noh->get_proximo();
    }
    cout << endl;
}