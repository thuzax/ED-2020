#include <iostream>

#include "Heap.hpp"

using namespace std;

int main() {
    Heap h = Heap(10);
    h.add(2, 1);
    h.add(10, 3);
    h.add(8, 2);
    h.add(4, 4);
    h.add(7, 5);
    h.add(6, 2);
    h.add(5, 7);
    h.add(1, 9);
    h.add(3, 3);

    cout << h.get_string() << endl;

    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    cout << h.remove() << endl;
    cout << h.get_string() << endl;
    return 0;
}