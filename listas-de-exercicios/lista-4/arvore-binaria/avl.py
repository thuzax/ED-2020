class NohAVL:
    def __init__(self, indice):
        self.indice = indice
        self.pai = None
        self.direita = None
        self.esquerda = None
        self.altura = 1


    def eh_maior(self, noh):
        if (self.indice > noh.indice):
            return True
        return False


    def __str__(self):
        texto = ""
        texto += str(self.indice) + "(" + str(self.altura) + ")"
        return texto



class AVL:
    def __init__(self):
        self.raiz = None

    def calcula_altura(self, noh):
        if (noh is None):
            return 0
        return noh.altura

    def calcula_balanceamento(self, noh):
        if (noh is None):
            return 0
        balanceamento = (self.calcula_altura(noh.esquerda)
                         - self.calcula_altura(noh.direita))
        return balanceamento


    def rotaciona_esquerda(self, noh):
        auxiliar = noh.direita
        noh.direita = auxiliar.esquerda

        # faz o pai da nova esquerda ser o noh
        if (noh.esquerda is not None):
            if (auxiliar.esquerda is not None):
                auxiliar.esquerda.pai = noh
        
        # atualiza o pai da antiga esquerda
        auxiliar.pai = noh.pai

        # Substitui a esquerda antiga no lugar do noh
        if (noh.pai is not None):
            esq = noh.pai.esquerda
            if ((esq is not None) and (noh.indice == esq.indice)):
                noh.pai.esquerda = auxiliar
            else:
                noh.pai.direita = auxiliar

        # atualiza os pais
        auxiliar.esquerda = noh
        noh.pai = auxiliar

        # atualiza alturas
        altura_noh_esquerda = self.calcula_altura(noh.esquerda)
        altura_noh_direita = self.calcula_altura(noh.direita)
        
        noh.altura = max(altura_noh_esquerda, altura_noh_direita) + 1

        altura_aux_esquerda = self.calcula_altura(noh.esquerda)
        altura_aux_direita = self.calcula_altura(noh.direita)

        auxiliar.altura = max(altura_aux_direita, altura_aux_esquerda) + 1

        return auxiliar


    def rotaciona_direita(self, noh):
        auxiliar = noh.esquerda
        noh.esquerda = auxiliar.direita


        # faz o pai da nova direita ser o noh
        if (noh.direita is not None):
            if (auxiliar.direita is not None):
                auxiliar.direita.pai = noh
        
        # atualiza o pai da antiga direita
        auxiliar.pai = noh.pai

        # Substitui a direita antiga no lugar do noh
        if (noh.pai is not None):
            esq = noh.pai.esquerda
            if ((esq is not None) and (noh.indice == esq.indice)):
                noh.pai.esquerda = auxiliar
            else:
                noh.pai.direita = auxiliar

        # atualiza os pais
        auxiliar.direita = noh
        noh.pai = auxiliar

        # atualiza alturas
        altura_noh_esquerda = self.calcula_altura(noh.esquerda)
        altura_noh_direita = self.calcula_altura(noh.direita)
        
        noh.altura = max(altura_noh_esquerda, altura_noh_direita) + 1

        altura_aux_esquerda = self.calcula_altura(auxiliar.esquerda)
        altura_aux_direita = self.calcula_altura(noh.direita)

        auxiliar.altura = max(altura_aux_direita, altura_aux_esquerda) + 1

        return auxiliar



    def balanceia(self, noh):
        altura_esquerda = self.calcula_altura(noh.esquerda)
        altura_direita = self.calcula_altura(noh.direita)
        noh.altura = max(altura_direita, altura_esquerda) + 1


        bal_noh = self.calcula_balanceamento(noh)
        bal_esquerda = self.calcula_balanceamento(noh.esquerda)
        bal_direita = self.calcula_balanceamento(noh.direita)

        if ((bal_noh >= -1) and (bal_noh <= 1)):
            print("Nao roda")
            return noh

        if ((bal_noh > 1) and (bal_esquerda >= 0)):
            print("Roda direita")
            return self.rotaciona_direita(noh)
        
        if ((bal_noh > 1) and (bal_esquerda < 0)):
            print("Roda esquerda depois direita")
            noh.esquerda = self.rotaciona_esquerda(noh.esquerda)
            return self.rotaciona_direita(noh)

        if ((bal_noh < -1) and (bal_direita <= 0)):
            print("Roda esquerda")
            return self.rotaciona_esquerda(noh)

        if ((bal_noh < -1) and (bal_direita > 0)):
            print("Roda direita depois esquerda")
            noh.direita = self.rotaciona_direita(noh.direita)
            noh.direita.pai = noh
            return self.rotaciona_esquerda(noh)


        return None


    def adiciona_recursivo(self, noh, novo):
        if (noh is None):
            return novo
        
        if (noh.eh_maior(novo)):
            noh.esquerda = self.adiciona_recursivo(noh.esquerda, novo)
            noh.esquerda.pai = noh

        elif (novo.eh_maior(noh)):
            noh.direita = self.adiciona_recursivo(noh.direita, novo)
            noh.direita.pai = noh
        
        else: # Impede repetição de chave
            return noh

        return self.balanceia(noh)


    def adiciona(self, indice):
        novo = NohAVL(indice)
        self.raiz = self.adiciona_recursivo(self.raiz, novo)
        print(self.raiz)


    def busca_recursiva(self, noh, item):
        passos = 1
        if (noh is None):
            return ("Não achou", passos)
        if (noh.indice == item):
            return ("Achou", passos)
        if (noh.indice > item):
            texto, passos_retorno = self.busca_recursiva(noh.esquerda, item)
            passos += passos_retorno
            return (texto, passos)
        if (noh. indice < item):
            texto, passos_retorno = self.busca_recursiva(noh.direita, item)
            passos += passos_retorno
            return (texto, passos)
        
        return (texto, passos)

        

    def busca(self, item):
        return self.busca_recursiva(self.raiz, item)



    def get_texto_itens_descendo_recursivo(self, noh):
        if (noh is None):
            return ""
        

        texto = "["
        
        texto += str(noh) + ": "
        
        
        if (noh.esquerda is not None):
            texto += "e=" + str(noh.esquerda)

        if (noh.esquerda is not None and noh.direita is not None):
            texto += ", "

        if (noh.direita is not None):
            texto += "d=" + str(noh.direita)
        
        texto += "] "
        
        if ((noh.direita is None) and (noh.esquerda is None)):
            return texto

        texto += self.get_texto_itens_descendo_recursivo(noh.esquerda)
        texto += self.get_texto_itens_descendo_recursivo(noh.direita)

        return texto


    def get_texto_itens_descendo(self):
        texto = ""
        texto += self.get_texto_itens_descendo_recursivo(self.raiz)
        return texto


    def get_texto_itens_em_ordem_recursivo(self, noh):
        if (noh is None):
            return ""
        
        texto = self.get_texto_itens_em_ordem_recursivo(noh.esquerda)
        texto += str(noh) + " "
        texto += self.get_texto_itens_em_ordem_recursivo(noh.direita)
        return texto


    def get_texto_itens_em_ordem(self):
        texto = self.get_texto_itens_em_ordem_recursivo(self.raiz)
        return texto
        
        


