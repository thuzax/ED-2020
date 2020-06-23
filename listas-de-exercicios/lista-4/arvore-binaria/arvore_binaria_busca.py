class NohBusca:
    def __init__(self, indice):
        self.indice = indice
        self.pai = None
        self.direita = None
        self.esquerda = None

    def eh_maior(self, noh):
        if (self.indice > noh.indice):
            return True

        return False

    def __str__(self):
        texto = ""
        texto += str(self.indice)
        return texto



class ArvoreBinariaBusca:
    def __init__(self):
        self.raiz = None

    def adiciona(self, indice):
        novo = NohBusca(indice)
        if (self.raiz is None):
            self.raiz = novo
            return
        
        noh = self.raiz
        pai = None
        insere_a_direita = False
        while (noh is not None):
            pai = noh
            if (novo.eh_maior(noh)):
                noh = noh.direita
                insere_a_direita = True
            else:
                noh = noh.esquerda
                insere_a_direita = False
        
        if (insere_a_direita):
            pai.direita = novo
            return

        pai.esquerda = novo
        novo.pai = pai

    


    def get_texto_itens_descendo_recursivo(self, noh):
        # texto = str(noh.indice) + " "
        if (noh is None):
            return ""
        
        if ((noh.direita is None) and (noh.esquerda is None)):
            return ""

        texto = "["
        # if (noh.pai is not None):
        texto += str(noh) + ": "
        
        if (noh.esquerda is not None):
            texto += "e=" + str(noh.esquerda)

        if (noh.esquerda is not None and noh.direita is not None):
            texto += ", "

        if (noh.direita is not None):
            texto += "d=" + str(noh.direita)
        
        texto += "] "
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
        
        


