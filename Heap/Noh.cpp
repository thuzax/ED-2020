
#include "Noh.hpp"

Noh::Noh(int dado) {
    this->dado = dado;
}

void Noh::set_dado(int dado) {
    this->dado = dado;
}

int Noh::get_dado() {
    return this->dado;
}