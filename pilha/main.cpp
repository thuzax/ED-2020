#include <iostream>

#include "Pilha.hpp"

using namespace std;

int main() {

    Pilha p = Pilha();

    p.empilhar(1);
    p.empilhar(2);
    p.empilhar(3);
    p.empilhar(4);
    p.empilhar(5);
    p.empilhar(6);
    p.empilhar(7);
    p.empilhar(8);
    p.empilhar(9);
    p.empilhar(10);

    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;

    p.empilhar(1);
    p.empilhar(2);
    p.empilhar(3);
    cout << p.desempilhar() << " " << p.desempilhar() << endl;

    p.empilhar(4);
    p.empilhar(5);
    p.empilhar(6);
    p.empilhar(7);
    p.empilhar(8);
    p.empilhar(9);
    p.empilhar(10);

    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;
    cout << p.desempilhar() << endl;

    return 0;
}