#include <iostream>

#include "busca.hpp"

using namespace std;

int main() {
    VetorBusca vetor_sequencial;

    cout << "--------------------Insercao sequencial------------------" << endl;

    vetor_sequencial.inserir(10);
    vetor_sequencial.inserir(3);
    vetor_sequencial.inserir(8);
    vetor_sequencial.inserir(11);
    vetor_sequencial.inserir(12);

    cout << vetor_sequencial.get_string() << endl;

    cout << "Busca sequencial: " << endl;

    cout << vetor_sequencial.busca_sequencial(3) << endl;
    cout << vetor_sequencial.busca_sequencial(8) << endl;
    cout << vetor_sequencial.busca_sequencial(10) << endl;
    cout << vetor_sequencial.busca_sequencial(11) << endl;
    cout << vetor_sequencial.busca_sequencial(12) << endl;




    VetorBusca vetor_ordenado;

    cout << "---------------------Insercao binaria--------------------" << endl;

    vetor_ordenado.inserir_ordenado(10);
    vetor_ordenado.inserir_ordenado(3);
    vetor_ordenado.inserir_ordenado(8);
    vetor_ordenado.inserir_ordenado(11);
    vetor_ordenado.inserir_ordenado(12);

    cout << vetor_ordenado.get_string() << endl;

    cout << "Busca sequencial: " << endl;

    cout << vetor_ordenado.busca_sequencial(3) << endl;
    cout << vetor_ordenado.busca_sequencial(8) << endl;
    cout << vetor_ordenado.busca_sequencial(10) << endl;
    cout << vetor_ordenado.busca_sequencial(11) << endl;
    cout << vetor_ordenado.busca_sequencial(12) << endl;

    cout << "Busca binaria: " << endl;

    cout << vetor_ordenado.busca_binaria(3) << endl;
    cout << vetor_ordenado.busca_binaria(8) << endl;
    cout << vetor_ordenado.busca_binaria(10) << endl;
    cout << vetor_ordenado.busca_binaria(11) << endl;
    cout << vetor_ordenado.busca_binaria(12) << endl;



    return 0;
}