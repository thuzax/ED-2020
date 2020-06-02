

#include "FilaComCauda.hpp"

//-----------------------------------FilaComCauda------------------------------
FilaComCauda::FilaComCauda() {
    this->inicio = nullptr;
    this->fim = nullptr;
}

FilaComCauda::~FilaComCauda() {
    while (this->inicio != nullptr) {
        Elemento* elemento = this->inicio;
        this->inicio = this->inicio->get_proximo();
        delete elemento;
    }
}

int FilaComCauda::remove_inicio() {
    if (this->inicio == nullptr) {
        cerr << "PILHA VAZIA" << endl;
        exit(1);
    }
    Elemento* elemento = this->inicio;
    if (this->fim == this->inicio) {
        this->fim = nullptr;
    }

    this->inicio = this->inicio->get_proximo();
    int dado = elemento->get_dado();
    delete elemento;
    return dado;
}

void FilaComCauda::insere_fim(int dado) {
    Elemento* novo = new Elemento(dado);
    if (this->inicio == nullptr) {
        this->inicio = novo;
        this->fim = novo;
        return;
    }

    this->fim->set_proximo(novo);
    this->fim = novo; 

}
