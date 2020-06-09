
#include "Noh.hpp"

Noh::Noh(int dado, double peso) {
    this->dado = dado;
    this->peso = peso;
}

void Noh::set_dado(int dado) {
    this->dado = dado;
}

void Noh::set_peso(double peso) {
    this->peso = peso;
}

int Noh::get_dado() {
    return this->dado;
}

double Noh::get_peso() {
    return this->peso;
}