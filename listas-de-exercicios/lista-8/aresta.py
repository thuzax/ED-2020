from vertice import Vertice

class Aresta:
    def __init__(self, vertice_1, vertice_2, capacidade):
        self.vertice_1 = vertice_1
        self.vertice_2 = vertice_2
        self.capacidade = capacidade
        self.fluxo = 0
        self.residual = capacidade

    def esta_cheia(self):
        if (self.fluxo < self.capacidade):
            return False

        return True
    
    def atualiza_residual(self):
        self.residual = self.capacidade - self.fluxo

    def get_string(self):
        texto = ""
        texto += str((self.vertice_1, self.vertice_2))
        texto += ": "
        texto += str(self.fluxo)
        texto += "/"
        texto += str(self.capacidade)
        texto += "\n"

        return texto
