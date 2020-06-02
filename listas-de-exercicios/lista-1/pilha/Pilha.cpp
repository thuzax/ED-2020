

#include "Pilha.hpp"


//-------------------------------------Elemento---------------------------------
Elemento::Elemento(int dado) {
    this->dado = dado;
    this->proximo = nullptr;
}

void Elemento::set_proximo(Elemento* proximo) {
    this->proximo = proximo;
}

int Elemento::get_dado() {
    return this->dado;
}

Elemento* Elemento::get_proximo() {
    return this->proximo;
}


//-----------------------------------Pilha------------------------------
Pilha::Pilha() {
    this->inicio = nullptr;
}

Pilha::~Pilha() {
    while (this->inicio != nullptr) {
        Elemento* elemento = this->inicio;
        this->inicio = this->inicio->get_proximo();
        delete elemento;
    }
}

void Pilha::insere_na_pilha(int dado) {
    Elemento* novo = new Elemento(dado);
    if (this->inicio == nullptr) {
        this->inicio = novo;
        return;
    }
    novo->set_proximo(this->inicio);
    this->inicio = novo;
}

int Pilha::remove_da_pilha() {
    if (this->inicio == nullptr) {
        cerr << "PILHA VAZIA" << endl;
        exit(1);
    }
    Elemento* elemento = this->inicio;
    this->inicio = this->inicio->get_proximo();
    int dado = elemento->get_dado();
    delete elemento;
    return dado;
}