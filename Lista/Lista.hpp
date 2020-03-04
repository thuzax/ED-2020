// Lista

#include "Noh.hpp"

using namespace std;

class Lista {
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;

    public:
        Lista();
        ~Lista();
        void adicionaNoh(int dado);
        
        void setDado(int posicao, int dado);
        
        void removePorPosicao(int posicao);
        void removePorDado(int dado);
        
        int getDadoPorPosicao(int posicao);
        void imprimiLista(); 

};