import sys

class MatrizAdjacencia:
    def __init__(self, num_vertices, arestas):
        self.num_vertices = num_vertices
        
        self.matriz = {}
        for i in range(self.num_vertices):
            self.matriz[i] = {}
            for j in range(self.num_vertices):
                self.matriz[i][j] = 0
        
        for v1, v2, peso in arestas:
            self.matriz[v1][v2] = peso
            

    def get_espaco_alocado(self):
        quantidade_bytes = 0
        for i in range(self.num_vertices):
            for j in range(self.num_vertices):
                quantidade_bytes += sys.getsizeof(self.matriz[i][j])
        
        quantidade_bytes += sys.getsizeof(self.num_vertices)
        return quantidade_bytes


    def bellman_ford(self, origem):
        distancias = []
        pais = []
        for i in range(self.num_vertices):
            distancias[i] = 999999999
            pais = None

        distancias[origem] = 0

        for i in range(self.num_vertices):
            pass


    def get_string(self, equivalencia_nomes=None):
        texto = ""
        if (equivalencia_nomes is None):
            texto += "  |"
            for i in range(self.num_vertices):
                texto += "  " + str(i) + "  |"
            texto += "\n"
            
            texto += "-------------------------------------------------------------"
            texto += "-------------------------"
            texto += "\n"

            for i in range(self.num_vertices):
                texto += str(i) + " |"
                
                for j in range(self.num_vertices):
                    texto += "  " + str(self.matriz[i][j]) + "  |"
                
                texto += "\n"
        else:
            texto += "  |"
            for i in range(self.num_vertices):
                texto += "  " + str(equivalencia_nomes[i]) + "  |"
            texto += "\n"
            
            texto += "  "
            for i in range(self.num_vertices):
                texto += " -----"
            texto += "\n"

            for i in range(self.num_vertices):
                texto += str(equivalencia_nomes[i]) + " |"
                
                for j in range(self.num_vertices):
                    texto += "  " + str(self.matriz[i][j]) + "  |"
                
                texto += "\n"
        return texto

