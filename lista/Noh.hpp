// Noh de uma lista


#ifndef NOH_HPP
#define NOH_HPP 1

using namespace std;

class Noh {
    private:
        int dado;
        Noh* proximo;
        Noh* anterior;
    
    public:
        Noh(int dado);
        void set_dado(int dado);
        int get_dado();
        void set_proximo(Noh* proximo);
        void set_anterior(Noh* anterior);
        Noh* get_proximo();
        Noh* get_anterior();
};

#endif