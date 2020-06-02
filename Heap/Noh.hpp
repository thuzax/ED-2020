// Nó de  uma heap

#include <iostream>

using namespace std;

class Noh {
    private:
        int dado;
        double peso;

    public:
        Noh(int dado, double peso);

        void set_dado(int dado);
        void set_peso(double peso);
        int get_dado();
        double get_peso();
};