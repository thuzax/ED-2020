class ListaAdjacencia:
    def __init__(self, num_vertices, arestas):
        self.num_vertices = num_vertices
        
        self.lista = []
        for i in range(self.num_vertices):
            self.lista.append([])

        for v1, v2 in arestas:
            self.lista[v1].append(v2)
            self.lista[v2].append(v1)

    def get_string(self):
        texto = ""
        
        for i in range(self.num_vertices):
            vizinhos = self.lista[i]
            texto += str(i) + " -> "
            
            for vizinho in vizinhos:
                texto += str(vizinho) + ", "
            
            texto += "\n"
        
        return texto