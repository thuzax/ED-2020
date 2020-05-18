#include <iostream>

#include "Heap.hpp"

using namespace std;

int main() {
    Heap h = Heap(10);
    h.adiciona(2);
    h.adiciona(10);
    h.adiciona(8);
    h.adiciona(4);
    h.adiciona(7);
    h.adiciona(6);
    h.adiciona(5);
    h.adiciona(1);
    h.adiciona(3);




    h.imprime();
    return 0;
}