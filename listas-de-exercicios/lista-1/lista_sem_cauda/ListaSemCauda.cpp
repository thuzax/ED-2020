

#include "ListaSemCauda.hpp"


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


//-----------------------------------ListaSemCauda------------------------------
ListaSemCauda::ListaSemCauda() {
    this->inicio = nullptr;
}

ListaSemCauda::~ListaSemCauda() {
    while (this->inicio != nullptr) {
        Elemento* elemento = this->inicio;
        this->inicio = this->inicio->get_proximo();
        delete elemento;
    }
}

void ListaSemCauda::insere_inicio(int dado) {
    Elemento* novo = new Elemento(dado);
    if (this->inicio == nullptr) {
        this->inicio = novo;
        return;
    }
    novo->set_proximo(this->inicio);
    this->inicio = novo;
}

void ListaSemCauda::insere_fim(int dado) {
    Elemento* novo = new Elemento(dado);
    if (this->inicio == nullptr) {
        this->inicio = novo;
        return;
    }

    Elemento* elemento = this->inicio;

    while (elemento->get_proximo() != nullptr) {
        elemento = elemento->get_proximo();
    }

    elemento->set_proximo(novo);

}

string ListaSemCauda::get_lista_string() {
    string text = "";
    Elemento* elemento = this->inicio;
    while (elemento != nullptr) {
        text += to_string(elemento->get_dado()) + " ";
        elemento = elemento->get_proximo();
    }
    return text;
}

