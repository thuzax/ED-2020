
#include "Heap.hpp"

Heap::Heap(int tamanho_maximo, bool crescente) {
    this->contador_id = 0;

    this->tamanho_maximo = tamanho_maximo;
    this->crescente = crescente;

    this->vetor = new Noh*[this->tamanho_maximo];
    this->tamanho = 0;

}

Heap::~Heap() {
    for (int i = 0; i < tamanho; i++) {
        delete this->vetor[i];
    }
    delete[] this->vetor;
}

bool Heap::verifica_ordem_anterior(Noh* noh, Noh* anterior) {
    if (this->crescente) {
        return (noh->get_dado() >= anterior->get_dado());
    }
    else {
        return (noh->get_dado() <= anterior->get_dado());
    }
}

bool Heap::verifica_ordem_proxima(Noh* noh, Noh* proximo) {
    if (this->crescente) {
        return (noh->get_dado() >= proximo->get_dado());
    }
    else {
        return (noh->get_dado() <= proximo->get_dado());
    }
}

bool Heap::heap_vazia() {
    if (this->tamanho == 0) {
        return true;
    }

    return false;
}

bool Heap::heap_cheia() {
    if (this->tamanho >= tamanho_maximo) {
        return true;
    }

    return false;
}

int Heap::pos_pai(int pos_filho) {
    return ((pos_filho - 1) / 2);
}

int Heap::pos_direita(int pos_pai) {
    return (2 * pos_pai + 2);
}

int Heap::pos_esquerda(int pos_pai) {
    return (2* pos_pai + 1);
}

void Heap::corrige_subindo(int pos) {
    Noh* noh = this->vetor[pos];
    int p_pai = this->pos_pai(pos);
    Noh* pai = this->vetor[p_pai];
    if (not verifica_ordem_anterior(noh, pai)) {
        this->vetor[p_pai] = noh;
        this->vetor[pos] = pai;
        return corrige_subindo(p_pai);
    }

    return;
}

void Heap::adiciona(int dado) {
    if (this->heap_cheia()) {
        cout << "Heap cheia" << endl;
        return;
    }
    
    Noh* novo = new Noh(dado);
    this->vetor[this->tamanho] = novo;
    this->tamanho++;

    corrige_subindo(this->tamanho-1);

}

void Heap::set_dado(int id, int dado) {

}

int Heap::remove() {
    return 0;
}

void Heap::imprime() {
    for(int i = 0; i < this->tamanho; i++) {
        cout << this->vetor[i]->get_dado() << " ";
    }
    cout << endl;
}

void Heap::imprime_ordenado() {

}
