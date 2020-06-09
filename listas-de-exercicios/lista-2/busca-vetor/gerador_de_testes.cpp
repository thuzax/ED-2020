
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
    int quantidade;
    cin >> quantidade;
    int num_buscas;
    cin >> num_buscas;

    int vetor_aleatorio[quantidade];

    srand(time(0));

    for (int i = 0; i < quantidade; i++) {
        int elemento;
        elemento = (rand() % (quantidade * 10));

        // Caso deseje elementos que nao repitam, descomente o codigo abaixo
        // bool gerou_diferente = false;
        // while (not gerou_diferente) {
        //     elemento = (rand() % (quantidade * 10));
        //     bool diferente = true;
        //     for (int j = 0; j < i+1 and diferente; j++) {
        //         if (elemento == vetor_aleatorio[j]) {
        //             diferente = false;
        //         }
        //     }
        //     gerou_diferente = diferente;
        // }
        vetor_aleatorio[i] = elemento;
    }

    string nome_saida = "teste_tamanho_" + to_string(quantidade) + ".in";

    ofstream saida(nome_saida.c_str());

    for (int i = 0; i < quantidade; i++) {
        cout << vetor_aleatorio[i] << " ";
        saida << vetor_aleatorio[i] << " ";
    }

    cout << endl;
    saida << endl;

    saida << vetor_aleatorio[0] << endl;
    saida << vetor_aleatorio[quantidade-1] << endl;

    int posicoes[num_buscas-2];

    for (int i = 0; i < num_buscas-2; i++) {
        int pos;
        bool gerou_diferente = false;
        while (not gerou_diferente) {
            pos = (rand() % (quantidade - 1)) + 1;
            bool diferente = true;
            for (int j = 0; j < i+1 and diferente; j++) {
                if (pos == posicoes[j]) {
                    diferente = false;
                }
            }
            gerou_diferente = diferente;
        }
        posicoes[i] = pos;
        saida << vetor_aleatorio[pos] << endl;
    }

    saida << endl;

    return 0;
}