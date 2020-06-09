

#include <iostream>
#include <string>

using namespace std;


#ifndef VETOR_BUSCA
#define VETOR_BUSCA



class VetorBusca {
    private:
        const int tam_maximo = 1000;
        int tam_atual; // tamanho atual do vetor
        int* vetor;

        bool cheio();
    public:
        /* inicializa o vetor, colocando todos os números como -1 para designar posição vazia e indicar o tamanhoAtual como 0 */
        VetorBusca();
        
        /* desaloca os ponteiros */
        ~VetorBusca();
        
        /* insere um elemento do tipo int em um vetor, na primeira posição livre */
        int inserir(int elemento);

        /* insere um elemento no vetor de forma a mantê-lo ordenado. */
        int inserir_ordenado(int elemento);

        /* retorna a posição onde um elemento está em um vetor, e retorna -1 caso não seja encontrado, utilizando busca sequencial */
        int busca_sequencial(int elemento);

        /* retorna a posição onde um element está em um vetor, e retorna -1 caso não seja encontrado, utilizando busca binária, e considerando que o vetor passado está ordenado. */
        int busca_binaria(int element);

        /* funções auxiliares para testar a busca com primeiro e ultimo elemento do vetor */
        int get_primeiro_elemento();
        int get_ultimo_elemento();

        string get_string();

};

#endif