#include <iostream>
#include <string>

#include "Pilha.hpp"

using namespace std;

int main() {
    Pilha* pilha = new Pilha();

    pilha->insere_na_pilha(10);
    pilha->insere_na_pilha(2);
    pilha->insere_na_pilha(3);
    pilha->insere_na_pilha(7);
    pilha->insere_na_pilha(9);
    pilha->insere_na_pilha(2);
    pilha->insere_na_pilha(0);
    pilha->insere_na_pilha(6);
    pilha->insere_na_pilha(8);
    pilha->insere_na_pilha(9);
    pilha->insere_na_pilha(10);
    pilha->insere_na_pilha(107);
    pilha->insere_na_pilha(107);

    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;
    cout << pilha->remove_da_pilha() << endl;

    delete pilha;
    return 0;
}