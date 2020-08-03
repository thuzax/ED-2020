import sys

from matriz_adj import MatrizAdjacencia
from lista_adj import ListaAdjacencia

class Grafo:
    ''' Argumentos: 
                número de vértices 
                nomes dos vertices
                pares de arestas
    '''
    def __init__(self, num_vertices, nomes_vertices, arestas_por_nome):
        self.num_vertices = num_vertices
        self.num_arestas = len(arestas_por_nome)

        self.nomes_vertices = nomes_vertices
        self.indices_vertices = {}

        self.arestas = []

        ind = 0
        for v in self.nomes_vertices:
            self.indices_vertices[v] = ind
            ind += 1

        for aresta_por_nome in arestas_por_nome:
            v1 = self.indices_vertices[aresta_por_nome[0]]
            v2 = self.indices_vertices[aresta_por_nome[1]]
            peso = aresta_por_nome[2]
            aresta = (v1, v2, peso)
            self.arestas.append(aresta)

        self.grafo = MatrizAdjacencia(self.num_vertices, self.arestas)
    
    def get_num_vertices(self):
        return self.num_vertices

    def get_num_arestas(self):
        return self.num_arestas

    def get_grau_medio(self):
        return (2 * self.num_arestas / self.num_vertices)

    def get_espaco_alocado(self):
        tam_grafo = self.grafo.get_espaco_alocado()
        tam_grafo += sys.getsizeof(self.num_arestas)
        tam_grafo += sys.getsizeof(self.num_arestas)

        return tam_grafo

    def bellman_ford(self, origem):
        self.grafo.bellman_ford(origem)


    def get_string(self):
        texto = self.grafo.get_string(self.nomes_vertices)
        return texto
