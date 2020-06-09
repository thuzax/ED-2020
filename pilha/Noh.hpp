// Noh de uma pilha

#ifndef NOH_HPP
#define NOH_HPP 1

using namespace std;

class Noh {
    private:
        int dado;
        Noh* anterior;
    
    public:
        Noh(int dado);

        void set_anterior(Noh* anterior);
        
        Noh* get_anterior();
        int get_dado();
};

#endif