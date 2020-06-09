

#include "busca.hpp"


VetorBusca::VetorBusca(){
    this->vetor = new int[this->tam_maximo];

    for (int i = 0; i < this->tam_maximo; i++) {
        this->vetor[i] = -1;
    }

    this->tam_atual = 0;
}

VetorBusca::~VetorBusca(){
    delete[] this->vetor;
}

bool VetorBusca::cheio() {
    if (this->tam_atual < this->tam_maximo) {
        return false;
    }
    return true;
}

int VetorBusca::inserir(int elemento){
    if (this->cheio()) {
        return -1;
    }

    this->vetor[this->tam_atual] = elemento;
    this->tam_atual++;

    return 0;
}

int VetorBusca::inserir_ordenado(int elemento){
    if (this->cheio()) {
        return -1;
    }


    int pos_insercao = 0;
    bool continua_maior = (elemento >= this->vetor[0]);
    while (pos_insercao < tam_atual and continua_maior) {
        pos_insercao++;
        continua_maior = (elemento >= this->vetor[pos_insercao]);
    }

    if (pos_insercao == tam_atual) {
        this->inserir(elemento);
        return 0;
    }

    int* novo_vetor = new int[this->tam_maximo];

    for (int i = 0; i < pos_insercao; i++) {
        novo_vetor[i] = this->vetor[i];
    }

    novo_vetor[pos_insercao] = elemento;

    for (int i = pos_insercao; i < (this->tam_maximo-1); i++) {
        novo_vetor[i+1] = this->vetor[i];
    }

    delete[] this->vetor;
    this->vetor = novo_vetor;

    this->tam_atual++;

    return 0;

}

int VetorBusca::busca_sequencial(int elemento){
    for (int i = 0; i < this->tam_atual; i++) {
        if (this->vetor[i] == elemento) {
            return i;
        }
    }

    return -1;

}

int VetorBusca::busca_binaria(int element){
    int end = this->tam_atual-1;
    int start = 0;
    int i = (start+end)/2;
    while (end >= start and element != this->vetor[i]) {
        if (element < this->vetor[i]) {
            end = i-1;
        }
        else {
            start = i+1;
        }
        i = (start+end)/2;
    }

    if (start > end) {
        return -1;
    }

    return i;

}

int VetorBusca::get_primeiro_elemento() {
    return this->vetor[0];
}

int VetorBusca::get_ultimo_elemento() {
    return this->vetor[this->tam_atual-1];
}

string VetorBusca::get_string(){
    string text = "";
    
    for (int i = 0; i < this->tam_atual; i++) {
        text += to_string(this->vetor[i]) + " ";
    }

    return text;
}

