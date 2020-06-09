
#include "Noh.hpp"

Noh::Noh(int dado) {
    this->dado = dado;
    this->anterior = nullptr;
}

void Noh::set_anterior(Noh* anterior) {
    this->anterior = anterior;
}

Noh* Noh::get_anterior() {
    return this->anterior;
}

int Noh::get_dado() {
    return this->dado;
}