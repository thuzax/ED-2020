#include "Noh.hpp"

Noh::Noh(int dado){
    this->dado = dado;
    this->anterior = nullptr;
    this->proximo = nullptr;
}

void Noh::set_dado(int dado) {
    this->dado = dado;
}

int Noh::get_dado() {
    return this->dado;
}

void Noh::set_proximo(Noh* proximo) {
    this->proximo = proximo;
}

void Noh::set_anterior(Noh* anterior) {
    this->anterior = anterior;
}

Noh* Noh::get_proximo() {
    return this->proximo;
}

Noh* Noh::get_anterior() {
    return this->anterior;
}

