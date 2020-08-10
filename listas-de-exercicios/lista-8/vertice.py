class Vertice:
    def __init__(self, idx):
        self.idx = idx
        self.colorido = False
        self.anterior = None

    def get_string(self):
        texto = ""
        
        texto += "id: " + str(self.idx) + "\n"
        
        texto += "cor: "
        texto += "branco" if not self.colorido else "cinza/preto"
        texto += "\n"
        
        texto += "pai: "
        if (self.anterior is not None):
            texto += str(self.anterior.idx)
        
        texto += "\n"
        
        return texto