// Noh de uma lista (ou árvore)


using namespace std;

class Noh {
    private:
        int dado;
        Noh* proximo;
        Noh* anterior;
    
    public:
        Noh(int dado);
        void setDado(int dado);
        int getDado();
        void setProximo(Noh* proximo);
        void setAnterior(Noh* anterior);
        Noh* getProximo();
        Noh* getAnterior();        
};