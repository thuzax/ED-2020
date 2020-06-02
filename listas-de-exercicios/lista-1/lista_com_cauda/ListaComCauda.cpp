

#include "ListaComCauda.hpp"


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


//-----------------------------------ListaComCauda------------------------------
ListaComCauda::ListaComCauda() {
    this->inicio = nullptr;
    this->fim = nullptr;
}

ListaComCauda::~ListaComCauda() {
    while (this->inicio != nullptr) {
        Elemento* elemento = this->inicio;
        this->inicio = this->inicio->get_proximo();
        delete elemento;
    }
}

void ListaComCauda::insere_inicio(int dado) {
    Elemento* novo = new Elemento(dado);
    if (this->inicio == nullptr) {
        this->inicio = novo;
        this->fim = novo;
        return;
    }
    novo->set_proximo(this->inicio);
    this->inicio = novo;
}

void ListaComCauda::insere_fim(int dado) {
    Elemento* novo = new Elemento(dado);
    if (this->inicio == nullptr) {
        this->inicio = novo;
        this->fim = novo;
        return;
    }

    this->fim->set_proximo(novo);
    this->fim = novo; 

}

string ListaComCauda::get_lista_string() {
    string text = "";
    Elemento* elemento = this->inicio;
    while (elemento != nullptr) {
        text += to_string(elemento->get_dado()) + " ";
        elemento = elemento->get_proximo();
    }
    return text;
}