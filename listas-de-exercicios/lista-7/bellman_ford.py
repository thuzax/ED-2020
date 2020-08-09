import sys

class BellmanFord:
    def __init__(self, num_vertices, arestas):
        self.num_vertices = num_vertices
        self.arestas = arestas
        self.contador = 0

    def relaxar(self, custos, pais, u, v, peso):
        self.contador += 1
        if (peso == 0):
            return None
        peso_relaxado = custos[u] + peso
        if (custos[v] > peso_relaxado):
            # relaxa
            custos[v] = peso_relaxado
            pais[v] = u


    def bellman_ford(self, origem):
        self.contador = 0
        VALOR_GRANDE = 999999999
        custos = []
        pais = []
        for i in range(self.num_vertices):
            custos.append(VALOR_GRANDE)
            pais.append(None)

        custos[origem] = 0

        for i in range(self.num_vertices-1):
            for u, v, peso in self.arestas:
                self.relaxar(custos, pais, u, v, peso)


        for u, v, peso in self.arestas:
            if (peso == 0):
                continue
            if (custos[v] > custos[u] + peso):
                return None

        return (custos, pais)

