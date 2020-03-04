
#include "Noh.hpp"

Noh::Noh(int dado) {
    this->dado = dado;
    this->proximo = nullptr;
}

int Noh::get_dado() {
    return this->dado;
}

Noh* Noh::get_proximo() {
    return this->proximo;
}

void Noh::set_proximo(Noh* proximo) {
    this->proximo = proximo;
}

