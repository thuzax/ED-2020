#include <iostream>

#include "Fila.hpp"

using namespace std;

int main() {

    Fila f = Fila();

    f.enfileirar(1);
    f.enfileirar(2);
    f.enfileirar(3);
    f.enfileirar(4);
    f.enfileirar(5);
    f.enfileirar(6);
    f.enfileirar(7);
    f.enfileirar(8);
    f.enfileirar(9);
    f.enfileirar(10);

    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;

    f.enfileirar(1);
    f.enfileirar(2);
    f.enfileirar(3);
    cout << f.desenfileirar() << " " << f.desenfileirar() << endl;

    f.enfileirar(4);
    f.enfileirar(5);
    f.enfileirar(6);
    f.enfileirar(7);
    f.enfileirar(8);
    f.enfileirar(9);
    f.enfileirar(10);

    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    cout << f.desenfileirar() << endl;
    


    return 0;
}