#include "Noh.hpp"

Noh::Noh(int dado){
    this->dado = dado;
    this->anterior = nullptr;
    this->proximo = nullptr;
}

void Noh::setDado(int dado) {
    this->dado = dado;
}

int Noh::getDado() {
    return this->dado;
}

void Noh::setProximo(Noh* proximo) {
    this->proximo = proximo;
}

void Noh::setAnterior(Noh* anterior) {
    this->anterior = anterior;
}

Noh* Noh::getProximo() {
    return this->proximo;
}

Noh* Noh::getAnterior() {
    return this->anterior;
}

