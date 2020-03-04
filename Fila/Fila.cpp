
#include "Fila.hpp"

Fila::Fila() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
}

Fila::~Fila() {
    Noh* noh = this->inicio;
    while (noh != nullptr) {
        this->inicio = this->inicio->get_proximo();
        delete noh;
        noh = this->inicio;
    }
}

bool Fila::fila_vazia() {
    return (this->tamanho== 0);
}

void Fila::enfileirar(int dado) {
    Noh* novo = new Noh(dado);

    if (this->fila_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }

    this->fim->set_proximo(novo);
    this->fim = novo;
    this->tamanho++;

}

int Fila::desenfileirar() {
    if (this->fila_vazia()) {
        cout << "Lista vazia" << endl;
        return -1;
    }
    int dado = this->inicio->get_dado();

    Noh* noh = this->inicio;
    this->inicio = this->inicio->get_proximo();

    delete noh;
    this->tamanho--;

    return dado;

}