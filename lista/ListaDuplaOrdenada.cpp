
#include "ListaDuplaOrdenada.hpp"


ListaDuplaOrdenada::ListaDuplaOrdenada(bool crescente) 
                        : ListaOrdenada(crescente){}

bool ListaDuplaOrdenada::verifica_ordem_proximo(Noh* noh, Noh* proximo) {
    if (proximo == nullptr) {
        return true;
    }

    if (this->crescente) {
        return (noh->get_dado() < proximo->get_dado());
    }
    else {
        return (noh->get_dado() > proximo->get_dado());
    }
}

bool ListaDuplaOrdenada::verifica_ordem_anterior(Noh* noh, Noh* anterior) {
    if (anterior == nullptr) {
        return true;
    }

    if (this->crescente) {
        return (noh->get_dado() > anterior->get_dado());
    }
    else {
        return (noh->get_dado() < anterior->get_dado());
    }
}

void ListaDuplaOrdenada::remove_noh(Noh* noh) {
    if (noh->get_anterior() == nullptr) {
        this->inicio = noh->get_proximo();
    }
    else {
        noh->get_anterior()->set_proximo(noh->get_proximo());
    }

    if (noh->get_proximo() == nullptr) {
        this->fim = noh->get_anterior();
    }
    
    else {
        noh->get_proximo()->set_anterior(noh->get_anterior());
    }

    delete noh;
    this->tamanho--;
}

void ListaDuplaOrdenada::aloca_entre_nohs(Noh* noh, 
                                    Noh* noh_ini, Noh* noh_fim) {

    bool insere_pelo_fim = verifica_ordem_anterior(noh, noh_fim);
    bool posicao_encontrada = (verifica_ordem_proximo(noh, noh_ini) 
                              or insere_pelo_fim);


    while (not posicao_encontrada) {
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
        insere_pelo_fim = verifica_ordem_anterior(noh, noh_fim);
        posicao_encontrada = (verifica_ordem_proximo(noh, noh_ini) 
                              or insere_pelo_fim);

    }
    

    if (insere_pelo_fim) {
        if (noh_fim->get_proximo() == nullptr) {
            this->fim = noh;
        }
        else {
            noh_fim->get_proximo()->set_anterior(noh);
        }
        noh->set_proximo(noh_fim->get_proximo());
        noh->set_anterior(noh_fim);
        noh_fim->set_proximo(noh);
    }

    else {
        if (noh_ini->get_anterior() == nullptr) {
            this->inicio = noh;
        }
        else {
            noh_ini->get_anterior()->set_proximo(noh);
        }
        noh->set_anterior(noh_ini->get_anterior());
        noh->set_proximo(noh_ini);
        noh_ini->set_anterior(noh);
    }
    

}

void ListaDuplaOrdenada::adiciona(int dado) {
    Noh* novo = new Noh(dado);

    if (this->lista_vazia()) {
        this->inicio = novo;
        this->fim = novo;
        this->tamanho++;
        return;
    }

    this->aloca_entre_nohs(novo, this->inicio, this->fim);
    this->tamanho++;

}

void ListaDuplaOrdenada::remove_por_posicao(int posicao) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return;
    }

    Noh* noh_ini = this->inicio;
    Noh* noh_fim = this->fim;

    int posicao_fim = this->tamanho - posicao - 1;
    bool comecar_do_fim = (posicao_fim < posicao);
    
    while (posicao > 0 and posicao_fim > posicao) {
        posicao--;
        posicao_fim--;
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
    }

    if (comecar_do_fim) {
        this->remove_noh(noh_fim);
        return;
    }

    this->remove_noh(noh_ini);
}

void ListaDuplaOrdenada::remove_por_dado(int dado) {
    // remove todos os nós com o mesmo valor de dado
}

void ListaDuplaOrdenada::set_dado(int posicao, int dado) {
    if (not this->posicao_valida(posicao)) {
        cout << "Posicao invalida" << endl;
        return;
    }

    Noh* noh_ini = this->inicio;
    Noh* noh_fim = this->fim;

    int posicao_fim = this->tamanho - posicao - 1;
    bool comecar_do_fim = (posicao_fim < posicao);

    while (posicao > 0 and posicao_fim > 0) {
        posicao--;
        posicao_fim--;
        noh_ini = noh_ini->get_proximo();
        noh_fim = noh_fim->get_anterior();
    }
    
    Noh* proximo;
    Noh* anterior;
    Noh* noh;

    if (comecar_do_fim) {
        noh_fim->set_dado(dado);
        noh = noh_fim;
    }
    else {
        noh_ini->set_dado(dado);
        noh = noh_ini;
    }

    anterior = noh->get_anterior();
    proximo = noh->get_proximo();


    bool anterior_certo = verifica_ordem_anterior(noh, anterior);
    bool proximo_certo = verifica_ordem_proximo(noh, proximo);


    if (anterior_certo and proximo_certo) {
        return;
    }
    

    if (proximo != nullptr) {
        proximo->set_anterior(anterior);
    }
    
    if (anterior != nullptr) {
        anterior->set_proximo(proximo);
    }

    if (anterior_certo) {
        noh_ini = proximo;
        noh_fim = this->fim;
    }

    else {
        noh_fim = anterior;
        noh_ini = this->inicio;
    }
    

    if (anterior_certo and anterior == nullptr) {
        this->inicio = noh->get_proximo();
    }

    if (proximo_certo and proximo == nullptr) {
        this->fim = noh->get_anterior();
    }

    this->aloca_entre_nohs(noh, noh_ini, noh_fim);
}


int ListaDuplaOrdenada::get_dado_por_posicao(int posicao) {
    // retorna o dado do nó na posicao
    return -1;
}