#include <iostream>
#include <string>

#include "FilaComCauda.hpp"
#include "FilaSemCauda.hpp"

using namespace std;

int main() {
    FilaComCauda* fila_com_cauda = new FilaComCauda();

    fila_com_cauda->insere_fim(10);
    fila_com_cauda->insere_fim(22);
    fila_com_cauda->insere_fim(13);
    fila_com_cauda->insere_fim(73);
    fila_com_cauda->insere_fim(94);
    fila_com_cauda->insere_fim(25);
    fila_com_cauda->insere_fim(0);
    fila_com_cauda->insere_fim(107);
    fila_com_cauda->insere_fim(10);
    fila_com_cauda->insere_fim(24);
    fila_com_cauda->insere_fim(31);
    fila_com_cauda->insere_fim(72);
    fila_com_cauda->insere_fim(19);
    fila_com_cauda->insere_fim(20);
    fila_com_cauda->insere_fim(1000);
    fila_com_cauda->insere_fim(107);

    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;
    cout << fila_com_cauda->remove_inicio() << endl;

    delete fila_com_cauda;

    cout << "---------------------------------------------------------" << endl;

    FilaSemCauda* fila_sem_cauda = new FilaSemCauda();

    fila_sem_cauda->insere_fim(10);
    fila_sem_cauda->insere_fim(22);
    fila_sem_cauda->insere_fim(13);
    fila_sem_cauda->insere_fim(73);
    fila_sem_cauda->insere_fim(94);
    fila_sem_cauda->insere_fim(25);
    fila_sem_cauda->insere_fim(0);
    fila_sem_cauda->insere_fim(107);
    fila_sem_cauda->insere_fim(10);
    fila_sem_cauda->insere_fim(24);
    fila_sem_cauda->insere_fim(31);
    fila_sem_cauda->insere_fim(72);
    fila_sem_cauda->insere_fim(19);
    fila_sem_cauda->insere_fim(20);
    fila_sem_cauda->insere_fim(1000);
    fila_sem_cauda->insere_fim(107);

    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;
    cout << fila_sem_cauda->remove_inicio() << endl;

    delete fila_sem_cauda;
    return 0;
}