

#include "FilaSemCauda.hpp"

//-----------------------------------FilaSemCauda------------------------------
FilaSemCauda::FilaSemCauda() {
    this->inicio = nullptr;
}

FilaSemCauda::~FilaSemCauda() {
    while (this->inicio != nullptr) {
        Elemento* elemento = this->inicio;
        this->inicio = this->inicio->get_proximo();
        delete elemento;
    }
}

int FilaSemCauda::remove_inicio() {
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

void FilaSemCauda::insere_fim(int dado) {
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

