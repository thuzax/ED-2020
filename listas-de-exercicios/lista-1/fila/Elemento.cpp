

#include "Elemento.hpp"


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