
#include <iostream>
#include "ListaDupla.hpp"

void ListaDupla::remove_noh(Noh* noh) {
    if (noh->get_anterior() == nullptr) {
        this->inicio = noh->get_proximo();
    }
    else {
        noh->get_anterior()->set_proximo(noh->get_proximo());
    }

    if (noh->get_proximo() == nullptr) {
        this->fim = noh->get_anterior();
    }
    else {
        noh->get_proximo()->set_anterior(noh->get_anterior());
    }

    delete noh;
    this->tamanho--;
}


void ListaDupla::adiciona_no_inicio(int dado) {
    Noh* novo = new Noh(dado);

    if (this->lista_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }

    this->inicio->set_anterior(novo);
    novo->set_proximo(this->inicio);
    this->inicio = novo;
    this->tamanho++;

}

void ListaDupla::adiciona_no_final(int dado) {
    Noh* novo = new Noh(dado);

    if (this->lista_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }

    this->fim->set_proximo(novo);
    novo->set_anterior(this->fim);
    this->fim = novo;
    this->tamanho++;
}

void ListaDupla::adiciona_na_posicao(int posicao, int dado) {
    // percorre a lista (assim como no set_dado)
    // arruma os ponteiros (verificando inicio e fim)
}


void ListaDupla::set_dado(int posicao, int dado) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return;
    }

    Noh* noh_ini = this->inicio;
    Noh* noh_fim = this->fim;

    int posicao_fim = this->tamanho - posicao - 1;
    bool comecar_do_fim = (posicao_fim < posicao);

    while (posicao > 0 and posicao_fim > 0) {
        posicao--;
        posicao_fim--;
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
    }
    
    if (comecar_do_fim) {
        noh_fim->set_dado(dado);
        return;
    }

    noh_ini->set_dado(dado);

}

void ListaDupla::remove_por_posicao(int posicao) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return;
    }

    Noh* noh_ini = this->inicio;
    Noh* noh_fim = this->fim;

    int posicao_fim = this->tamanho - posicao - 1;
    bool comecar_do_fim = (posicao_fim < posicao);
    
    while (posicao > 0 and posicao_fim > posicao) {
        posicao--;
        posicao_fim--;
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
    }

    if (comecar_do_fim) {
        this->remove_noh(noh_fim);
        return;
    }

    this->remove_noh(noh_ini);

}

void ListaDupla::remove_por_dado(int dado) {
    if (this->lista_vazia()) {
        return;
    }


    Noh* noh_ini = this->inicio;
    Noh* noh_fim = this->fim;

    int posicao_ini = 0;
    int posicao_fim = this->tamanho - 1;

    while (posicao_ini <= posicao_fim) {
        if (noh_ini->get_dado() == dado) {
            this->remove_noh(noh_ini);
        }
        if (posicao_ini != posicao_fim and noh_fim->get_dado() == dado) {
            this->remove_noh(noh_fim);
        }
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
        posicao_ini++;
        posicao_fim--;
    }

}

int ListaDupla::get_dado_por_posicao(int posicao) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return -1;
    }

    Noh* noh_ini = this->inicio;
    Noh* noh_fim = this->fim;

    int posicao_fim = this->tamanho - 1;
    bool comecar_do_fim = (posicao > posicao_fim);

    while (posicao > 0 and posicao_fim > 0) {
        posicao--;
        posicao_fim--;
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
    }

    if (comecar_do_fim) {
        return noh_fim->get_dado();
    }

    return noh_ini->get_dado();

}