#include <iostream>
#include <string>

#include "ListaComCauda.hpp"

using namespace std;

int main() {
    ListaComCauda* lista = new ListaComCauda();

    lista->insere_fim(107);
    lista->insere_inicio(10);
    lista->insere_inicio(2);
    lista->insere_inicio(3);
    lista->insere_inicio(7);
    lista->insere_inicio(9);
    lista->insere_inicio(2);
    lista->insere_inicio(0);
    lista->insere_fim(6);
    lista->insere_fim(8);
    lista->insere_fim(9);
    lista->insere_fim(10);
    lista->insere_fim(107);
    lista->insere_inicio(107);

    cout << lista->get_lista_string() << endl;

    delete lista;
    return 0;
}