// Noh de fila

#ifndef NOH_HPP
#define NOH_HPP 1


using namespace std;

class Noh {
    private:
        int id;
        int dado;
        Noh* proximo;

    public:
        Noh(int dado);

        void set_proximo(Noh* proximo);
        
        Noh* get_proximo();
        int get_dado();
};

#endif