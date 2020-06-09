#include <iostream>
#include <string>
#include <fstream>

#include "busca.hpp"

using namespace std;

int main() {

    int qtd_entradas = 3;
    int tamanhos_entradas[qtd_entradas] = {10, 100, 1000};
    
    int qtd_buscas = 5;

    for (int i = 0; i < qtd_entradas; i++) {
        string nome_arquivo = ("teste_tamanho_" 
                               + to_string(tamanhos_entradas[i]) 
                               + ".in");
        ifstream entrada;
        
        //----------------------------------------------------------------------
        entrada.open(nome_arquivo);

        VetorBusca vetor_sequencial;
        
        cout << "------------------Insercao sequencial----------------" << endl;

        for (int j = 0; j < tamanhos_entradas[i]; j++) {
            int elemento;
            entrada >> elemento;
            vetor_sequencial.inserir(elemento);
        }
        cout << vetor_sequencial.get_string() << endl;

        cout << "Busca sequencial: " << endl;
        for (int j = 0; j < qtd_buscas; j++) {
            int elemento;
            entrada >> elemento;
            int pos = vetor_sequencial.busca_sequencial(elemento);
            cout << "Elemento " << elemento << " encontrado na posicao: ";
            cout << pos << endl;
        }

        entrada.close();
        
        //---------------------------------------------------------------------
        
        entrada.open(nome_arquivo);

        VetorBusca vetor_ordenado;

        cout << "-------------------Insercao ordenada-----------------" << endl;

        for (int j = 0; j < tamanhos_entradas[i]; j++) {
            int elemento;
            entrada >> elemento;
            vetor_ordenado.inserir_ordenado(elemento);
        }
        cout << vetor_ordenado.get_string() << endl;

        int elementos[qtd_buscas];
        for (int j = 0; j < qtd_buscas; j++) {
            int elemento;
            entrada >> elemento;
            elementos[j] = elemento;
        }

        // Como a ordem de inserção modificou a ordem do arquivo, 
        // faz duas buscas extras, pelo primeiro e ultimo elemento
        int primeiro_elemento = vetor_ordenado.get_primeiro_elemento();
        int ultimo_elemento = vetor_ordenado.get_ultimo_elemento();

        cout << "Busca sequencial: " << endl;
        for (int j = 0; j < qtd_buscas; j++) {
            int pos = vetor_ordenado.busca_sequencial(elementos[j]);
            cout << "Elemento " << elementos[j] << " encontrado na posicao: ";
            cout << pos << endl;
        }

        int pos;

        pos = vetor_ordenado.busca_sequencial(primeiro_elemento);
        cout << "Primeiro elemento " << primeiro_elemento;
        cout << " encontrado na posicao: ";
        cout << pos << endl;
        
        pos = vetor_ordenado.busca_sequencial(ultimo_elemento);
        cout << "Ultimo elemento " << ultimo_elemento;
        cout << " encontrado na posicao: ";
        cout << pos << endl;
        
        cout << "Busca binaria: " << endl;
        for (int j = 0; j < qtd_buscas; j++) {
            int pos = vetor_ordenado.busca_binaria(elementos[j]);
            cout << "Elemento " << elementos[j] << " encontrado na posicao: ";
            cout << pos << endl;
        }

        pos = vetor_ordenado.busca_binaria(primeiro_elemento);
        cout << "Primeiro elemento: " << primeiro_elemento;
        cout << " encontrado na posicao ";
        cout << pos << endl;
        
        pos = vetor_ordenado.busca_binaria(ultimo_elemento);
        cout << "Ultimo elemento: " << ultimo_elemento;
        cout << " encontrado na posicao ";
        cout << pos << endl;
        
        entrada.close();
    }

    return 0;
}