class MatrizAdjacencia:
    def __init__(self, num_vertices, arestas):
        self.num_vertices = num_vertices
        
        self.matriz = []
        for i in range(self.num_vertices):
            self.matriz.append([])
            for j in range(self.num_vertices):
                self.matriz[i].append(0)
        
        for v1, v2 in arestas:
            self.matriz[v1][v2] = 1
            self.matriz[v2][v1] = 1
            
    def get_string(self):
        texto = ""
        
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
        
        return texto

