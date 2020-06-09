
#include "ListaOrdenada.hpp"

ListaOrdenada::ListaOrdenada(bool crescente) {
    this->crescente = crescente;
}

bool ListaOrdenada::verifica_ordem_proximo(Noh* noh, Noh* proximo) {
    return false;
}
bool ListaOrdenada::verifica_ordem_anterior(Noh* noh, Noh* anterior) {
    return false;
}

void ListaOrdenada::adiciona(int dado) {
    // adiciona dado na lista
}

void ListaOrdenada::remove_por_posicao(int posicao) {
    // remove nó pela posicao na lista
}

void ListaOrdenada::remove_por_dado(int dado) {
    // remove todos os nós com o mesmo valor de dado
}

void ListaOrdenada::set_dado(int posicao, int dado) {
    // altera o valor do dado do nó (mantém ordenação)
}


int ListaOrdenada::get_dado_por_posicao(int posicao) {
    // retorna o dado do nó na posicao
    return -1;
}